#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str = "";
	getline(cin, str);
	while (str.compare(".") != 0) {
		stack<char> S;
		bool Wrong = 0;
		for (auto i : str) {
			if (i == '[' || i == '(') {
				S.push(i);
			}
			else if (i == ']') {
				if (S.empty()) Wrong = 1;
				else if (S.top() == '[') {
					S.pop();
				}
				else Wrong = 1;
			}
			else if (i == ')') {
				if (S.empty()) Wrong = 1;
				else if (S.top() == '(') {
					S.pop();
				}
				else Wrong = 1;
			}
		}
		if (!S.empty()) Wrong = 1;
		if (Wrong == 0) cout << "yes\n";
		else cout << "no\n";
		getline(cin, str);
	}
}