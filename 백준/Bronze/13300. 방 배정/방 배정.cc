#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	int arr[2][6] = {};
	int S = 0, Y = 0;
	for (int i = 0; i < N; i++) {
		cin >> S >> Y;
		arr[S][Y - 1]++;
	}

	int room = 0;
	for (int i = 0; i < 2; i++) {
		for (int u = 0; u < 6; u++) {
			if (arr[i][u]) {
				if (arr[i][u] > K)
					room += (arr[i][u] + 1) / K;
				else room++;
			}
		}
	}
	cout << room;
}