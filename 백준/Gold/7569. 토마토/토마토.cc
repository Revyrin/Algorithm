#include <bits/stdc++.h>
using namespace std;

int board[100][100][100];
int dist[100][100][100];

int dx[6] = { 1, 0, -1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m, n, h;
	cin >> m >> n >> h;
	queue <tuple<int, int, int>> Q;

	fill(&dist[0][0][0], &dist[99][99][100], -1);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1) {
					Q.push({ i, j, k });
					dist[i][j][k] = 0;
				}
				if (board[i][j][k] == -1)
					dist[i][j][k] = 0;
			}
		}
	}

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int nz = get<0>(cur) + dz[dir];
			int nx = get<1>(cur) + dx[dir];
			int ny = get<2>(cur) + dy[dir];
			if (nx < 0 || ny < 0 || nz < 0 || nz >= h || nx >= n || ny >= m) continue;
			if (dist[nz][nx][ny] >= 0) continue;
			if (board[nz][nx][ny] == -1) continue;
			Q.push({ nz, nx, ny });
			dist[nz][nx][ny] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
		}
	}
	int cnt = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (dist[i][j][k] == -1) {
					cout << -1;
					return 0;
				}
				
				cnt = max(cnt, dist[i][j][k]);
			}
		}
	}
	cout << cnt;
}