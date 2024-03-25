#include <iostream>
using namespace std;
string s;
int ans;

// <문제 파악>
// 같은 문자가 연속해서 2번 나타나면 안 된다.
// → 이전에 어떤 문자가 쓰였는지만 기억하면 된다.

void go(int level, char prev) {
	if (level == s.size()) {
		ans++;
		return;
	}
	if (s[level] == 'c') {
		for (int i = 0; i < 26; i++) {
			char ch = i + 'a';
			if (ch != prev) {
				go(level + 1, ch);
			}
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			char ch = i + '0';
			if (ch != prev) {
				go(level + 1, ch);
			}
		}
	}
}

int main() {
	cin >> s;
	go(0, ' ');
	cout << ans;
}