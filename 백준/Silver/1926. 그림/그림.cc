#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[501][501];
bool vis[501][501];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};

	int cnt = 0;
	int area = 0, max_area = 0;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	queue<pair<int, int>> Q;

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			if (board[x][y] == 1 && vis[x][y] == 0) {
				area = 0;
				vis[x][y] = 1;
				Q.push({ x,y });
				area++;
				while (!Q.empty()) {
					pair<int, int> cur = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
						if (vis[nx][ny] || board[nx][ny] != 1) continue;
						vis[nx][ny] = 1;
						area++;
						Q.push({ nx, ny });
					}
				}
				if (area > max_area) max_area = area;
				cnt++;
			}
		}
	}
	cout << cnt << '\n' << max_area;
}