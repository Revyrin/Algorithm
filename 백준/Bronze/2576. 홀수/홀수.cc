#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int in;
	vector<int> v;
	int sum = 0;

	for (int i = 0; i < 7; i++) {
		cin >> in;
		if (in % 2 == 1) {
			sum += in; 
			v.push_back(in);
		}
	}

	if (sum == 0) cout << -1;
	else cout << sum << "\n" << *min_element(v.begin(), v.end());
}