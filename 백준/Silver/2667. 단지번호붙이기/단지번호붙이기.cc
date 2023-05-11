#include <bits/stdc++.h>
using namespace std;

string board[26];
int vis[26][26];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> board[i];

	queue<pair<int, int>> Q;
	vector<int> res;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == '0' || vis[i][j] == 1) continue;
			cnt++;
			Q.push({ i, j });
			vis[i][j] = 1;
			int area = 1;
			while (!Q.empty()) {
				auto cur = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					if (board[nx][ny] == '0' || vis[nx][ny] == 1) continue;
					Q.push({ nx, ny });
					vis[nx][ny] = 1;
					area++;
				}
			}
			res.push_back(area);
		}
	}
	sort(res.begin(), res.end());
	cout << cnt << '\n';
	for (int i : res) {
		cout << i << '\n';
	}
}