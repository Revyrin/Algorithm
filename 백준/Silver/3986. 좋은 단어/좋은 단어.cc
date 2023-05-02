#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	int n, cnt = 0;
	cin >> n;

	while (n--) {
		cin >> str;
		stack<char> S;
		for (auto i : str) {
			if (!S.empty() && S.top() == i) S.pop();
			else S.push(i);
		}
		if (S.empty()) cnt++;
	}
	cout << cnt;
}