#include <bits/stdc++.h>
using namespace std;

int dist[1000002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;
	fill(dist + 1, dist + f + 1, -1);

	queue<int> Q;
	Q.push(s);
	dist[s] = 0;

	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (auto nn : {cur + u, cur -d}) {
			if (nn < 1 || nn > f) continue;
			if (dist[nn] >= 0) continue;
			Q.push(nn);
			dist[nn] = dist[cur] + 1;
		}
	}
	if (dist[g] == -1) cout << "use the stairs";
	else cout << dist[g];
}