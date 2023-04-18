#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, X;
	cin >> N >> X;

	int t;
	for (int i = 0; i < N; i++) {
		cin >> t;
		if (X > t)	cout << t << " ";
	}
}