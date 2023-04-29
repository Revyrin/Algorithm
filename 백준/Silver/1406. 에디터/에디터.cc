#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str = "";
	int m = 0;
	cin >> str >> m;

	list<char> C = {};

	for (auto i : str)
		C.push_back(i);

	list<char>::iterator t = C.end();

	char in, in2;
	while (m > 0) {
		cin >> in;
		if (in == 'P') {
			cin >> in2;
			C.insert(t, in2);
		}
		if (in == 'L') {
			if (t != C.begin())	t--;
		}
		if (in == 'D') {
			if (t != C.end())	t++;
		}
		if (in == 'B') {
			if (t != C.begin()) {
				t--;
				t = C.erase(t);
			}
		}
		m--;
	}

	for (auto i : C)
		cout << i;
}