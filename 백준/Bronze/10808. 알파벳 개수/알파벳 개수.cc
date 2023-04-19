#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int ap[26] = {0};
	char arr[101];
	cin >> arr;

	for (int i = 0; arr[i] != '\0'; i++)
		ap[arr[i] - 'a']++;
        
	for (int i = 0; i < 26; i++)
		cout << ap[i] << " ";
}