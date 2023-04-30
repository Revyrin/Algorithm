#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x;
	cin >> n;
	deque<int> dq;

	while (n--) {
		string str;
		cin >> str;
		if (str.compare("push_front") == 0) {
			cin >> x;
			dq.push_front(x);
		}
		else if (str.compare("push_back") == 0) {
			cin >> x;
			dq.push_back(x);
		}
		else if (str.compare("pop_front") == 0) {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (str.compare("pop_back") == 0) {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (str.compare("size") == 0)
			cout << dq.size() << '\n';
		else if (str.compare("empty") == 0) {
			if (dq.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (str.compare("front") == 0) {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
			}
		}
		else if (str.compare("back") == 0) {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
			}
		}
	}
}