#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int K, sum = 0;
	cin >> K;
	stack<int> S;

	while (K--) {
		int x;
		cin >> x;
		if (x == 0) {
			if (!S.empty()) {
				sum -= S.top();
				S.pop();
			}
		}
		else {
			S.push(x);
			sum += x;
		}
	}
	cout << sum;
}