#include <iostream>
using namespace std;
int r, c, ans = 0;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
char a[20][20], check[26];

void go(int level, int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
			if (!check[a[nx][ny] - 'A']) {
				check[a[nx][ny] - 'A'] = true;
				go(level + 1, nx, ny);
				check[a[nx][ny] - 'A'] = false;
			}
		}
	}
	ans = max(ans, level);
}

int main() {
	// 1. input
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> a[i];
	}

	// 2. solve (brute force)
	check[a[0][0] - 'A'] = true;
	go(1, 0, 0);

	// 3. output
	cout << ans;
}