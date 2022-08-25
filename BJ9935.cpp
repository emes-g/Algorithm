#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// <문제 파악>
// 스택에 인덱스를 삽입/삭제하여 해결하는 문제
// 시간복잡도 : O(N)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	string str, exp, ans;
	cin >> str >> exp;
	if (exp.size() == 1) {	// 폭발 문자열 길이가 1인 경우
		for (int i = 0; i < str.size(); i++) {
			if (str[i] != exp[0]) {
				ans += str[i];
			}
		}
		cout << (ans.size() ? ans : "FRULA");
		return 0;
	}

	// 2. solve (stack)
	stack<int> s, e;
	for (int i = 0; i < str.size(); i++) {
		s.push(i);
		if (str[i] == exp[0]) {	// 현재 문자가 폭발 문자열의 첫 번째 문자와 동일
			e.push(0);
		}
		else {
			if (e.empty()) {
				continue;
			}
			else {
				int last = e.top();
				if (str[i] == exp[last + 1]) {	// 현재 문자가 폭발 문자열의 (last+1)번째 문자와 동일
					e.push(last + 1);
					if (last + 1 == exp.size() - 1) {	// 폭발 문자열이 완성된 경우
						for (int j = 0; j < exp.size(); j++) {
							s.pop();
							e.pop();
						}
					}
				}
				else {
					while (!e.empty()) {	// 폭발 문자열이 완성될 수 없는 문자가 들어온 경우
						e.pop();
					}
				}
			}
		}
	}
	while (!s.empty()) {
		ans += str[s.top()];
		s.pop();
	}
	reverse(ans.begin(), ans.end());
	cout << (ans.size() ? ans : "FRULA");
}