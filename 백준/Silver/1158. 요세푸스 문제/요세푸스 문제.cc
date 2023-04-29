#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	list<int> L;

	for (int i = 1; i <= N; i++) {
		L.push_back(i);
	}

	list<int>::iterator t = L.begin();

	cout << '<';
	while (!L.empty()) {
		for (int i = 0; i < K; i++) {
			if (t == L.end()) {
				t = L.begin();
				t++;
			}
			else t++;
		}
		t--;
		cout << *t;
		t = L.erase(t);
		if (!L.empty())
			cout << ", ";
	}
	cout << '>';
}