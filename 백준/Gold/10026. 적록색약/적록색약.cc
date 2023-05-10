#include <bits/stdc++.h>
using namespace std;
string board[101];
int vis[101][101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

queue<pair<int, int>> Q;
int cnt, n;

void bfs(int i, int j) {
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
			if (vis[nx][ny] == 1 || board[cur.first][cur.second] != board[nx][ny]) continue;
			Q.push({ nx, ny });
			vis[nx][ny] = 1;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] == 0) {
				bfs(i, j);
			}
		}
	}
	cout << cnt << ' ';

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'G')
				board[i][j] = 'R';
		}
	}
	cnt = 0;
	for (int i = 0; i < n; i++) fill(vis[i], vis[i] + n, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] == 0) {
				bfs(i, j);
			}
		}
	}
	cout << cnt;
}