#include <bits/stdc++.h>
using namespace std;
string board[1001];
int dist1[1001][1001];	// 지훈이
int dist2[1001][1001];	// 불
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int r, c;
	cin >> r >> c;

	queue<pair<int, int>> Q1;	// 지훈이
	queue<pair<int, int>> Q2;	// 불

	for (int i = 0; i < r; i++) {
		cin >> board[i];
		for (int j = 0; j < c; j++) {
			if (board[i][j] == 'J') {
				Q1.push({ i, j });
				dist2[i][j] = -1;
			}
			if (board[i][j] == '.') {
				dist1[i][j] = -1;
				dist2[i][j] = -1;
			}
			if (board[i][j] == 'F')
				Q2.push({ i, j });
		}
	}

	while (!Q2.empty()) {
		auto cur = Q2.front();
		Q2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (dist2[nx][ny] >= 0) continue;
			dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
			Q2.push({ nx,ny });
		}
	}

	while (!Q1.empty()) {
		auto cur = Q1.front();
		Q1.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
				cout << dist1[cur.first][cur.second] + 1;
				return 0;
			}
			if (dist1[nx][ny] >= 0) continue;
			if (dist2[nx][ny] <= dist1[cur.first][cur.second] + 1 && dist2[nx][ny] != -1) continue; // 불에 따라 잡히거나 F가 없을 경우의 예외 처리
			dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
			Q1.push({ nx,ny });
		}
	}
	cout << "IMPOSSIBLE";
}