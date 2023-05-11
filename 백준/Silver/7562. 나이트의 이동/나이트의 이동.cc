#include <bits/stdc++.h>
using namespace std;

int dist[301][301];

int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, i, flag = 0;
	cin >> t;

	while (t--) {
		cin >> i;

		for (int k = 0; k < i; k++) fill(dist[k], dist[k] + i, -1);
		queue<pair<int, int>> Q;

		int a, b;
		cin >> a >> b;
		Q.push({ a, b });
		dist[a][b] = 0;

		cin >> a >> b;

		if (Q.front().first == a && Q.front().second == b) {
			Q.pop();
			cout << 0 << '\n';
		}

		while (!Q.empty() && !flag) {
			auto cur = Q.front();
			Q.pop();
			for (int dir = 0; dir < 8; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || ny < 0 || nx >= i || ny >= i) continue;
				if (a == nx && b == ny) {
					cout << dist[cur.first][cur.second] + 1 << '\n';
					flag = 1;
				}
				if (dist[nx][ny] >= 0) continue;
				Q.push({ nx,ny });
				dist[nx][ny] = dist[cur.first][cur.second] + 1;
			}
		}
		flag = 0;
	}
}