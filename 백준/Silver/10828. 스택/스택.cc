#include <bits/stdc++.h>
using namespace std;

// 배열로 스택 구현
int st[10001];
int idx;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, X;
	cin >> N;
	string in;

	while (N--) {
		cin >> in;
		if (in == "push") {
			cin >> X;
			st[idx++] = X;
		}
		else if (in == "pop") {
			if (idx == 0)
				cout << -1 << '\n';
			else {
				cout << st[--idx] << '\n';
			}
		}
		else if (in == "size") {
			cout << idx << '\n';
		}
		else if (in == "empty") {
			if (idx == 0) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (in == "top") {
			if (idx == 0) cout << -1 << '\n';
			else cout << st[idx - 1] << '\n';
		}
	}
}