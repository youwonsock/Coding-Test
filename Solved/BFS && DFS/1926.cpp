#include <bits/stdc++.h>

using namespace std;

int board[502][502];
bool vis[502][502];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	queue<pair<int, int>> q;
	int n, m;

	int paintNum = 0;
	int maxPaintSize = 0;

	cin >> n >> m;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
			cin >> board[i][j];
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			// bfs
			if(vis[i][j] != true && board[i][j] == 1)
			{
				vis[i][j] = true;
				q.push({i, j});

				int currentPaintSize = 0;

				while(!q.empty())
				{
					pair<int, int> current = q.front(); q.pop();

					for(int k = 0; k < 4; ++k)
					{
						int nextX = current.first + dx[k];
						int nextY = current.second + dy[k];
						
						if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m)
							continue;

						if(vis[nextX][nextY] || board[nextX][nextY] != 1)
							continue;

						vis[nextX][nextY] = true;
						q.push({nextX, nextY});
					}

					currentPaintSize += 1;
				}

				paintNum += 1;

				if(currentPaintSize > maxPaintSize)
					maxPaintSize = currentPaintSize;
			}
		}
	}

	cout << paintNum << '\n';
	cout << maxPaintSize << '\n';

    return 0;
}