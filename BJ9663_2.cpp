#include <iostream>
using namespace std;
int n, ans, a[14];

// a[i] : i행에 존재하는 퀸의 위치 (열)

bool good(int level) {
	for (int i = level - 1; i >= 0; i--) {
		if (a[level] == a[i] || level - i == abs(a[level] - a[i])) {
			return false;
		}
	}
	return true;
}

void go(int level) {
	if (level == n) {
		ans++;
		return;
	}
	for (int i = 0; i < n; i++) {
		a[level] = i;
		if (good(level)) {
			go(level + 1);
		}
	}
}

int main() {
	cin >> n;
	go(0);
	cout << ans;
}