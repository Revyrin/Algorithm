#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int sum = 0, f = 0;
	vector<int> v(9);

	for (int i = 0; i < 9; i++) {
		cin >> v[i];
		sum += v[i];
	}

	for (int i = 0; i < v.size(); i++) {
		for (int k = i + 1; k < v.size(); k++)
			if ((sum - v[i] - v[k]) == 100) {
				v.erase(v.begin() + i);
				v.erase(v.begin() + k - 1);
				f = 1;
				break;
			}
		if (f) break;
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) cout << v[i] << "\n";
}