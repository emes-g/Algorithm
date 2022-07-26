#include <iostream>
using namespace std;
bool check[14][14];
int n, ans;

bool good(int x, int y) {	// 유망성 검사
	for (int i = x - 1; i >= 0; i--) {
		int l = y - (x - i);
		int r = y + (x - i);
		if (check[i][y] || (l >= 0 && check[i][l]) || (r < n && check[i][r])) {
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
		if (good(level, i)) {
			check[level][i] = true;
			go(level + 1);
			check[level][i] = false;	// 상태 복구
		}
	}
}

int main() {
	cin >> n;
	go(0);
	cout << ans;
}