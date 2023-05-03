#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;
	stack<char> S;	// stack에 '('만 저장하여 막대 갯수 저장
	long long cnt = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			S.push(str[i]);
		}
		else if (str[i] == ')') {
			if (str[i-1] == '(') { // 레이저
				S.pop();
				cnt += S.size();
			}
			else {	// 막대 끝이므로 막대 개수 감소
				S.pop();
				cnt++;	// 막대 1개 절단된 것과 같으므로 1 증가
			}
		}
	}
	cout << cnt;
}