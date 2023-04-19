#include <bits/stdc++.h>
using namespace std;

int arr[100000];
bool t[2000001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, X;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> X;
	
	int cnt = 0;
	
	for (int i = 0; i < N; i++) {
		if (X - arr[i] > 0 && t[X - arr[i]]) cnt++;
		t[arr[i]] = 1;
	}
	cout << cnt;
}