#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int k = 1; k < i; k++)
			cout << ' ';
		for (int k = (N - i + 1) * 2 - 1; k >= 1; k--)
			cout << '*';
		cout << "\n";
	}
}