#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> v(3);
	
	for (int i = 0; i < 3; i++)
		cin >> v[i];

	for (int i = 0; i < 3; i++) {
		for (int k = i; k < 3; k++) {
			if (v[i] > v[k]) {
				int tmp = v[i];
				v[i] = v[k];
				v[k] = tmp;
			}
		}
	}
	for (int i = 0; i < 3; i++)
		cout << v[i] << " ";
}