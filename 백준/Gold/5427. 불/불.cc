#include <bits/stdc++.h>
using namespace std;

string board[1001];
int dist1[1001][1001];	// 불
int dist2[1001][1001];	// 상근이

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	while (n--) {
		int w, h;
		cin >> w >> h;
		for (int i = 0; i < h; i++) fill(dist1[i], dist1[i] + w, -1);
		for (int i = 0; i < h; i++) fill(dist2[i], dist2[i] + w, -1);
		queue<pair<int, int>> Q1;
		queue<pair<int, int>> Q2;

		for (int i = 0; i < h; i++) {
			cin >> board[i];
			for (int j = 0; j < w; j++) {
				if (board[i][j] == '#') {
					dist1[i][j] = 0;
					dist2[i][j] = 0;
				}
				if (board[i][j] == '@') {
					dist2[i][j] = 0;
					Q2.push({ i, j });
				}
				if (board[i][j] == '*') {
					dist1[i][j] = 0;
					Q1.push({ i, j });
				}
			}
		}

		while (!Q1.empty()) {
			auto cur = Q1.front();
			Q1.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (dist1[nx][ny] >= 0) continue;
				Q1.push({ nx, ny });
				dist1[nx][ny] = dist1[cur.first][cur.second] + 1;
			}
		}
		int flag = 0;
		while (!Q2.empty() && !flag) {
			auto cur = Q2.front();
			Q2.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) {
					cout << dist2[cur.first][cur.second] + 1 << '\n';
					flag = 1;
					break;
				}
				if (dist2[nx][ny] >= 0) continue;
				if (dist1[nx][ny] <= dist2[cur.first][cur.second] + 1 && dist1[nx][ny] != -1) continue;
				Q2.push({ nx, ny });
				dist2[nx][ny] = dist2[cur.first][cur.second] + 1;
			}
		}
		if(flag == 0)
			cout << "IMPOSSIBLE" << '\n';
	}
}