#include <bits/stdc++.h>
using namespace std;

int dist[100002];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;	// 수빈 위치 n, 동생 위치 k
	cin >> n >> k;
	
	queue<int> Q;
	fill(dist, dist + 100002, -1);
	
	Q.push(n);
	dist[n] = 0;

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		for (int nxt : { cur - 1, cur + 1, cur * 2 }) {
			if (nxt < 0 || nxt > 100000) continue;
			if (dist[nxt] >= 0) continue;
			if (nxt == k) {
				cout << dist[cur] + 1;
				return 0;
			}
			Q.push(nxt);
			dist[nxt] = dist[cur] + 1;
		}
	}
	cout << 0;
}