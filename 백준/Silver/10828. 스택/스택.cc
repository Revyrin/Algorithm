#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	stack<int> st;
	string in;
	int X;

	while (N--) {
		cin >> in;
		if (in == "push") {
			cin >> X;
			st.push(X);
		}
		else if (in == "pop") {
			if (!st.empty()) {
				cout << st.top() << '\n';
				st.pop();
			}
			else cout << -1 << '\n';
		}
		else if (in == "size") {
			cout << st.size() << '\n';
		}
		else if (in == "empty") {
			if (st.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (in == "top") {
			if (!st.empty()) cout << st.top() << '\n';
			else cout << -1 << '\n';
		}
	}
}