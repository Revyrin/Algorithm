#include <bits/stdc++.h>
using namespace std;

void cmp_alp(string a, string b) {
	int alp[26] = {};
	int alp2[26] = {};

	for (auto i : a)
		alp[i - 'a']++;
	for (auto i : b)
		alp2[i - 'a']++;
	int cnt = 0;
	for (int i = 0; i < 26; i++)
		if (alp[i] == alp2[i]) cnt++;

	if (cnt == 26) cout << "Possible\n";
	else cout << "Impossible\n";
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	string a, b;

	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		cmp_alp(a, b);
	}
}