#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B, C;
	cin >> A >> B >> C;

	int res = A * B * C;
	int arr[10] = {};

	while (res > 0) {
		arr[res % 10]++;
		res /= 10;
	}

	for (auto i : arr)
		cout << i << "\n";	
}