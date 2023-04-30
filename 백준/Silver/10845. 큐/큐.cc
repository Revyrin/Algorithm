#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	queue<int> q;

	while (n--) {
		string in;
		int x;
		cin >> in;
		if (in == "push") {
			cin >> x;
			q.push(x);
		}
		else if (in == "pop") {
			if (q.empty()) cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (in == "size") {
			cout << q.size() << '\n';
		}
		else if (in == "empty") {
			if (q.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (in == "front") {
			if (q.empty()) cout << -1 << '\n';
			else cout << q.front() << '\n';
		}
		else if (in == "back") {
			if (q.empty()) cout << -1 << '\n';
			else cout << q.back() << '\n';
		}
	}
}