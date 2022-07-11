#include <iostream>
#include <string>
using namespace std;
char s[10][10], sign[10];
int a[10];
bool ok;

// 백트래킹

char getSign(int sum) {
	if (sum > 0) {
		return '+';
	}
	else if (sum < 0) {
		return '-';
	}
	else {
		return '0';
	}
}

bool check(int level) {
	for (int i = 0; i < level; i++) {
		int sum = 0;
		for (int j = i; j <= level; j++) {
			sum += a[j];
		}
		if (s[i][level] != getSign(sum)) {
			return false;
		}
	}
	return true;
}

void go(int level, int n) {
	if (level == n) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		ok = true;
		return;
	}

	if (s[level][level] == '0') {
		a[level] = 0;
		if (check(level)) {
			go(level + 1, n);
			if (ok) {
				return;
			}
		}
	}
	else if (s[level][level] == '+') {
		for (int i = 1; i <= 10; i++) {
			a[level] = i;
			if (check(level)) {
				go(level + 1, n);
			}
			if (ok) {
				return;
			}
		}
	}
	else {
		for (int i = -1; i >= -10; i--) {
			a[level] = i;
			if (check(level)) {
				go(level + 1, n);
			}
			if (ok) {
				return;
			}
		}
	}
}

int main() {
	int n, idx = 0;
	string str;
	cin >> n >> str;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			s[i][j] = str[idx++];
		}
	}
	for (int i = 0; i < n; i++) {
		sign[i] = s[i][i];
	}
	go(0, n);
	return 0;
}