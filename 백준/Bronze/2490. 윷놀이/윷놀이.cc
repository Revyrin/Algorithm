#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int sum;
	vector<int> v(4);

	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < 4; i++)
			cin >> v[i];
		sum = accumulate(v.begin(), v.end(), 0);
		if (sum == 0) cout << 'D';	// 윷
		else if (sum == 1) cout << 'C';	// 걸
		else if (sum == 2) cout << 'B'; // 개
		else if (sum == 3) cout << 'A'; // 도
		else cout << 'E';	// 모
		cout << '\n';
	}
}