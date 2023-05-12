#include <bits/stdc++.h>
using namespace std;

int board[101][101];
int vis[101][101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, cnt = 0, max_cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	queue<pair<int, int>> Q;
	for (int k = 0; k <= 100; k++) {
		cnt = 0;
		for (int t = 0; t < n; t++) fill(vis[t], vis[t] + n, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (vis[i][j] == 1 || board[i][j] <= k) continue;
				cnt++;
				Q.push({ i, j });
				vis[i][j] = 1;
				while (!Q.empty()) {
					auto cur = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
						if (vis[nx][ny] == 1 || board[nx][ny] <= k) continue;
						Q.push({ nx, ny });
						vis[nx][ny] = 1;
					}
				}
			}
		}
		max_cnt = max(cnt, max_cnt);
	}
	cout << max_cnt;
}