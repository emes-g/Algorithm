#include <iostream>
using namespace std;
int n, ans, a[14];

// <변수>
// a[i] : i행에 존재하는 퀸의 위치 (열)

// <비교>
// 기존 O(2)작업을 O(1)에 해결하여 시간 측면에서 좀 더 빠르다.
// 기존(방법 1) : 5.5s
// 신규(방법 2) : 4.5s

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
