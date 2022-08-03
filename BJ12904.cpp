#include <iostream>
#include <algorithm>
using namespace std;

// <접근 아이디어>
// 연산 1이든 2든 뒤에 하나씩 추가하는 연산이다.
// 그러면 S->T를 만들 것이 아니라,
// T→S를 만들어 보면 어떨까?

int main() {
	string s, t;
	cin >> s >> t;
	while (t.length() > s.length()) {
		if (t.back() == 'A') {
			t.pop_back();
		}
		else {
			t.pop_back();
			reverse(t.begin(), t.end());
		}
	}
	cout << (s == t ? 1 : 0);
}