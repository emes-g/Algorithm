#include <iostream>
#include <vector>
using namespace std;
int n, ans;
bool a[16][16];
int dx[3] = { 0,1,1 };
int dy[3] = { 1,0,1 };

// <변수 설명>
// dir	현재 파이프의 방향
// 0	오른쪽
// 1	아래
// 2	대각선

bool good(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < n && !a[x][y];
}

bool good2(int x, int y) {
	return good(x, y) && good(x - 1, y) && good(x, y - 1);
}

void go(int x, int y, int dir) {
	if (x == n - 1 && y == n - 1) {
		ans++;
		return;
	}
	int nx = x + dx[2];
	int ny = y + dy[2];
	if (good2(nx, ny)) {	// 대각선 이동
		go(nx, ny, 2);
	}
	if (dir != 0) {	// 아래로 이동
		nx = x + dx[1];
		ny = y + dy[1];
		if (good(nx, ny)) {
			go(nx, ny, 1);
		}
	}
	if (dir != 1) {	// 오른쪽으로 이동
		nx = x + dx[0];
		ny = y + dy[0];
		if (good(nx, ny)) {
			go(nx, ny, 0);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// 1. input
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	// 2. solve (brute force)
	go(0, 1, 0);
	cout << ans;
}