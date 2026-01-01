#include <bits/stdc++.h>
using namespace std;

string board[1002];
int f_vis[1002][1002];
int j_vis[1002][1002];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c; // 문제의 입력 순서(R, C) 확인 필요

    queue<pair<int, int>> qF;
    queue<pair<int, int>> qJ;

    // 1. 초기화: f_vis를 -1로 채워 불이 없는 상태를 표시
    for(int i = 0; i < r; i++) {
        fill(f_vis[i], f_vis[i] + c, -1);
        fill(j_vis[i], j_vis[i] + c, -1);
    }

    for(int i = 0; i < r; i++) {
        cin >> board[i];
        for(int j = 0; j < c; j++) {
            if(board[i][j] == 'F') {
                qF.push({i, j});
                f_vis[i][j] = 0; // 시작 시간 0
            }
            if(board[i][j] == 'J') {
                qJ.push({i, j});
                j_vis[i][j] = 0; // 시작 시간 0
            }
        }
    }

    // 불의 BFS
    while(!qF.empty()) {
        auto cur = qF.front(); qF.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(f_vis[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            f_vis[nx][ny] = f_vis[cur.first][cur.second] + 1;
            qF.push({nx, ny});
        }
    }

    // 지훈이의 BFS
    while(!qJ.empty()) {
        auto cur = qJ.front(); qJ.pop();
        for(int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            // 범위를 벗어났다 = 탈출 성공
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) {
                cout << j_vis[cur.first][cur.second] + 1;
                return 0;
            }

            if(j_vis[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            
            // 불이 이미 붙었거나, 지훈이가 도착함과 동시에 불이 붙는 경우 (f_vis[nx][ny] != -1 조건 중요)
            if(f_vis[nx][ny] != -1 && f_vis[nx][ny] <= j_vis[cur.first][cur.second] + 1) continue;

            j_vis[nx][ny] = j_vis[cur.first][cur.second] + 1;
            qJ.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}