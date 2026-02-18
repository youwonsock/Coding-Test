#include <bits/stdc++.h>

using namespace std;

int board[1002][1002];
int vis[1002][1002];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	int n, m;
	cin >> m >> n;

	queue<pair<int, int>> q;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
		
			if(board[i][j] == 1)
			{
				q.push({i, j});
				vis[i][j] = 1;
			}

			if(board[i][j] == -1)
				vis[i][j] = -1;
		}
	}

	while(!q.empty())
	{
		auto current = q.front(); q.pop();

		for(int i = 0; i < 4; ++i)
		{
			int nextX = current.first + dx[i];
			int nextY = current.second + dy[i];

			if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m)
				continue;

			if(vis[nextX][nextY] != 0)
				continue;

			vis[nextX][nextY] = vis[current.first][current.second] + 1;
			q.push({nextX, nextY});
		}
	}

	int ans = 0;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(vis[i][j] == 0)
			{
				cout << -1;
				return 0;
			}

			if(ans < vis[i][j])
				ans = vis[i][j];
		}
	}

	cout << ans - 1;
    
    return 0;
}