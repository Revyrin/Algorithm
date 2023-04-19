#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[9] = {};
	int in;
	cin >> in;

	int max = 0;

	while (in > 0) {
		if (in % 10 == 9)
			arr[6]++;
		else arr[in % 10]++;
		in /= 10;
	}
	if (arr[6] % 2) {
		arr[6] /= 2;
		arr[6]++;
	}
	else arr[6] /= 2;
	
	for (auto i : arr)
		if (i > max)	max = i;
	cout << max;
}