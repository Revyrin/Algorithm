#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long A, B;
	cin >> A >> B;
	if (A > B) swap(A, B);

	if (B != A) cout << B - A - 1 << "\n";
	else cout << 0 << "\n";

	for (long long i = A + 1; i < B; i++)
		cout << i << " ";
	
}