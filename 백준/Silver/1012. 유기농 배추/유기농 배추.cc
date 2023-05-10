#include <bits/stdc++.h>
using namespace std;

int board[51][51];
int vis[51][51];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	int m, n, k, cnt;
	while(t--) {
		cnt = 0;
		for (int i = 0; i < 51; i++) fill(board[i], board[i] + 51, 0);
		for (int i = 0; i < 51; i++) fill(vis[i], vis[i] + 51, 0);
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;
		}
		queue<pair<int, int>> Q;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (vis[j][i] == 0 && board[j][i] == 1) {
					cnt++;
					Q.push({ j, i });
					vis[j][i] = 1;

					while (!Q.empty()) {
						auto cur = Q.front();
						Q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];
							if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
							if (vis[nx][ny] == 1 || board[nx][ny] == 0) continue;
							Q.push({ nx, ny });
							vis[nx][ny] = 1;
						}
					}
				}
			}
		}
		cout << cnt << '\n';
	}
}