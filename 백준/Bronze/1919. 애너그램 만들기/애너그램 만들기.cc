#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	cin >> a >> b;
	int arr[26] = {};

	for (auto i : a) arr[i - 'a']++;
	for (auto i : b) arr[i - 'a']--;
	int cnt = 0;
	for (int i = 0; i < 26; i++)
		if (arr[i] != 0) cnt+= abs(arr[i]);
	cout << cnt;
}