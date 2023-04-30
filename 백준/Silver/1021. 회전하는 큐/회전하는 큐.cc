#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, cnt = 0;
	cin >> n >> m;
    
	deque<int> dq1;
	deque<int> dq2;

	for (int i = 1; i <= n; i++)
		dq1.push_back(i);
	dq2 = dq1;
	while (m--) {

		int x, lcnt = 0, rcnt = 0;
		cin >> x;
		while (dq1.front() != x) {
			if (!dq1.empty()) {
				dq1.push_back(dq1.front());
				dq1.pop_front();
				lcnt++;
			}
		}
		while (dq2.front() != x) {
			if (!dq2.empty()) {
				dq2.push_front(dq2.back());
				dq2.pop_back();
				rcnt++;
			}
		}
		if (lcnt < rcnt) {
			dq1.pop_front();
			cnt += lcnt;
			dq2 = dq1;
		}
		else {
			dq2.pop_front();
			cnt += rcnt;
			dq1 = dq2;
		}
	}
	cout << cnt;
}