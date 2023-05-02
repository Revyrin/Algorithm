#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		stack<char> S;
		string str;
		cin >> str;
		bool VPS = 1;

		for (auto i : str) {
			if (i == '(') S.push(i);
			else if (i == ')') {
				if (S.empty()) {
					VPS = 0;
					break;
				}
				if (S.top() == '(')
					S.pop();
			}
		}
		if (!S.empty()) VPS = 0;
		if (VPS == 1) cout << "YES\n";
		else cout << "NO\n";
	}
}