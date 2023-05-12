#include <bits/stdc++.h>
using namespace std;

string board[31][31];
int dist[31][31][31];

int dx[6] = { 1, 0, -1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int l = 1, r = 1, c = 1;
	int el, er, ec;
	cin >> l >> r >> c;
	while (l != 0 && r != 0 && c != 0) {
		fill(&dist[0][0][0], &dist[30][30][31], -1);
		queue<tuple<int, int, int>> Q;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				cin >> board[i][j];
				for (int k = 0; k < c; k++) {
					if (board[i][j][k] == 'S') {
						Q.push({ i, j, k });
						dist[i][j][k] = 0;
					}
					if (board[i][j][k] == '#')
						dist[i][j][k] = 0;
					if (board[i][j][k] == 'E')
						el = i, er = j, ec = k;
				}
			}
		}

		while (!Q.empty()) {
			auto cur = Q.front();
			Q.pop();
			int curX, curY, curZ;
			tie(curZ, curX, curY) = cur;
			for (int dir = 0; dir < 6; dir++) {
				int nz = curZ + dz[dir];
				int nx = curX + dx[dir];
				int ny = curY + dy[dir];
				if (nx < 0 || ny < 0 || nz < 0 || nz >= l || nx >= r || ny >= c) continue;
				if (dist[nz][nx][ny] >= 0) continue;
				Q.push({ nz, nx, ny });
				dist[nz][nx][ny] = dist[curZ][curX][curY] + 1;
			}
		}
		if (dist[el][er][ec] == -1)	cout << "Trapped!\n";
		else cout << "Escaped in " << dist[el][er][ec] << " minute(s).\n";
		cin >> l >> r >> c;
	}
}