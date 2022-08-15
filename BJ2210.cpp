#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<bool> check(1e6);
int a[5][5], g[6], ans;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int calc() {
	int res = 0;
	for (int i = 0; i < 6; i++) {
		res += g[i] * pow(10, 5 - i);
	}
	return res;
}

void go(int level, int x, int y) {
	if (level == 5) {
		int num = calc();
		if (!check[num]) {
			check[num] = true;
			ans++;
		}
		return;
	}
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
			g[level + 1] = a[nx][ny];
			go(level + 1, nx, ny);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j];
		}
	}
	
	// 2. solve (brute force)
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			g[0] = a[i][j];
			go(0, i, j);
		}
	}
	cout << ans;
}