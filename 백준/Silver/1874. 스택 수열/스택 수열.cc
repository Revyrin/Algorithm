#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, cnt = 1;
	int flag = 0;
	cin >> n;
	stack<int> st;
	string ans;

	while (n--) {
		int x;
		cin >> x;
		if (!st.empty()) {
			if (st.top() > x)
				flag = 1;
			else if (st.top() < x) {
				for (cnt; cnt <= x; cnt++) {
					st.push(cnt);
					ans += "+\n";
				}
				st.pop();
				ans += "-\n";
			}
			else if (st.top() == x) {
				st.pop();
				ans += "-\n";
			}
		}
		else if (st.empty()) {
			for (cnt; cnt <= x; cnt++) {
				st.push(cnt);
				ans += "+\n";
			}
			st.pop();
			ans += "-\n";
		}
	}

	if (flag == 1)	cout << "NO";
	else	cout << ans;
}