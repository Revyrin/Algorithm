#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N - 1; i++) {
		for (int k = i; k < N; k++)
			cout << ' ';
		for (int k = 1; k <= i * 2 - 1; k++)
			cout << '*';
		cout << "\n";
	}

	for (int i = 1; i <= N * 2 - 1; i++)	cout << '*';
	cout << '\n';

	for (int i = N - 1; i >= 1; i--) {
		for (int k = i; k < N; k++)
			cout << ' ';
		for (int k = 1; k <= i * 2 - 1; k++)
			cout << '*';
		cout << "\n";
	}
}