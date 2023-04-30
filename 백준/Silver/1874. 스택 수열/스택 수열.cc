#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, cnt = 1;
	int flag = 0;
	cin >> n;
	stack<int> st;
	stack<char> sn;
	char arr[200001] = {};

	while (n--) {
		int x;
		cin >> x;
		if (!st.empty()) {
			if (st.top() > x)
				flag = 1;
			else if (st.top() < x) {
				for (cnt; cnt <= x; cnt++) {
					st.push(cnt);
					sn.push('+');
				}
				st.pop();
				sn.push('-');
			}
			else if (st.top() == x) {
				st.pop();
				sn.push('-');
			}
		}
		else if (st.empty()) {
			for (cnt; cnt <= x; cnt++) {
				st.push(cnt);
				sn.push('+');
			}
			st.pop();
			sn.push('-');
		}
	}

	if (flag == 1)
		cout << "NO";
	else {
		int t = sn.size();
		for (int i = 0; i < t; i++) {
			arr[i] = sn.top();
			sn.pop();
		}
		for (int i = t - 1; i >= 0; i--)
			cout << arr[i] << '\n';
	}
}