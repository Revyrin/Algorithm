#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		string str;
		cin >> str;
		int n;
		cin >> n;
		string arr;
		cin >> arr;

		int flag = 0, er = 0;

		deque<int> dq;

		for (int i = 0; arr[i] != ']'; i++) {
			if (arr[i] != '[' && arr[i] != ']' && arr[i] != ',') {
				if (arr[i] == '1' && arr[i + 1] == '0' && arr[i + 2] == '0') {
					dq.push_back(100);
					i += 2;
				}
				else if (arr[i] >= '0' && arr[i] <= '9' && arr[i+1] >= '0' && arr[i+1] <= '9') {
					dq.push_back((arr[i] - '0') * 10 + (arr[i + 1] - '0'));
					i++;
				}
				else dq.push_back(arr[i] - '0');
			}
		}

		for (auto i : str) {
			if (i == 'R') {
				if (flag == 0)
					flag = 1;
				else flag = 0;
			}
			else if (i == 'D') {
				if (dq.empty()) {
					cout << "error\n";
					er = 1;
					break;
				}
				else {
					if (flag == 0) {
						dq.pop_front();
					}
					else if (flag == 1) {
						dq.pop_back();
					}
				}
			}
		}
		
		if (er == 0 && flag == 0) {
			cout << '[';
			while (!dq.empty()) {
				if (dq.size() == 1) {
					cout << dq.front();
					dq.pop_front();
				}
				else {
					cout << dq.front() << ',';
					dq.pop_front();
				}
			}
			cout << "]\n";
		}
		else if (er == 0 && flag == 1) {
			cout << '[';
			while (!dq.empty()) {
				if (dq.size() == 1) {
					cout << dq.back();
					dq.pop_back();
				}
				else {
					cout << dq.back() << ',';
					dq.pop_back();
				}
			}
			cout << "]\n";
		}
	}
}