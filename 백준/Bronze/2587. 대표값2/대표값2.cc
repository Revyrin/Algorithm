#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v(5);
	for (int i = 0; i < 5; i++)	cin >> v[i];

	sort(v.begin(), v.end());
	cout << accumulate(v.begin(), v.end(), 0) / v.size() << "\n" << v[2];
}