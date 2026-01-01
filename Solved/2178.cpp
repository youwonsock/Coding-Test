#include <bits/stdc++.h>

using namespace std;

int matrix[102][102];
bool vis[102][102];

int dx[4] = { 1, -1, 0, 0};
int dy[4] = { 0, 0, 1, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
    {
        string line;
        cin >> line;
        for(int j = 0; j < m; ++j)
            matrix[i][j] = line[j] - 48;
    }

    queue<pair<pair<int, int>, int>> q;
    int minDist = 9999;

    q.push({{0, 0}, 1});
    vis[0][0] = true;

    while(!q.empty())
    {
        auto current = q.front(); q.pop();

        for(int i = 0; i < 4; ++i)
        {
            int nextX = current.first.first + dx[i];
            int nextY = current.first.second + dy[i];
            
            if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m)
                continue;
                
            if(vis[nextX][nextY] == 1 || matrix[nextX][nextY] == 0)
                continue;

            vis[nextX][nextY] = 1;
            int dist = current.second + 1;
            q.push({{nextX, nextY}, dist});

            if(nextX == n-1 && nextY == m-1)
            {
                if(minDist > dist)
                    minDist = dist;
            }
        }
    }

    cout << minDist;

    return 0;
}