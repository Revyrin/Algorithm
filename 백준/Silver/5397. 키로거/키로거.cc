#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	list<char> L;
	while (N--) {
		string str;
		cin >> str;
		if(!L.empty())	
			L.clear();
		list<char>::iterator t = L.begin();
		for (auto i : str) {
			if (i == '<') {
				if (t != L.begin())
					t--;
			}
			else if (i == '>') {
				if (t != L.end())
					t++;
			}
			else if (i == '-') {
				if (t != L.begin()) {
					t--;
					t = L.erase(t);
				}
			}
			else {
				L.insert(t, i);
			}
		}
		for (auto i : L)
			cout << i;
		cout << '\n';
	}
}