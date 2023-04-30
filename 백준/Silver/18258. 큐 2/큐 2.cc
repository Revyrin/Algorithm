#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);

	int n;
	cin >> n;
	queue<int> q;

	while (n--) {
		string in;
		int x;
		cin >> in;
		if (in.compare("push") == 0) {
			cin >> x;
			q.push(x);
		}
		else if (in.compare("pop") == 0) {
			if (q.empty()) cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (in.compare("size") == 0) {
			cout << q.size() << '\n';
		}
		else if (in.compare("empty") == 0) {
			if (q.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (in.compare("front") == 0) {
			if (q.empty()) cout << -1 << '\n';
			else cout << q.front() << '\n';
		}
		else if (in.compare("back") == 0) {
			if (q.empty()) cout << -1 << '\n';
			else cout << q.back() << '\n';
		}
	}
}