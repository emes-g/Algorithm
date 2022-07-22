#include <iostream>
using namespace std;
char s[10][10];
int a[10];
bool ok;

bool good(int level) {
	int sum = 0;
	for (int i = level; i >= 0; i--) {
		sum += a[i];
		if (s[i][level] == '-') {
			if (sum >= 0) {
				return false;
			}
		}
		else if (s[i][level] == '+') {
			if (sum <= 0) {
				return false;
			}
		}
		else {
			if (sum != 0) {
				return false;
			}
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
	for (int i = -10; i <= 10; i++) {
		a[level] = i;
		if (good(level)) {
			go(level + 1, n);
		}
		if (ok) {
			return;
		}
	}
}

int main() {
	// 1. input
	int n, idx = 0;
	string str;
	cin >> n >> str;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			s[i][j] = str[idx++];
		}
	}
	
	// 2. solve (brute force)
	go(0, n);
}
