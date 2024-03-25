#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 100;
bool check[MAX][MAX];
char a[MAX][MAX], c[3] = { 'R','G','B' };
int n, ans[2];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void dfs(int x, int y) {
	check[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if (a[nx][ny] == a[x][y] && !check[nx][ny]) {
				dfs(nx, ny);
			}
		}
	}
}

void solve(int s) {
	memset(check, false, sizeof(check));
	for (int k = s; k < 3; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == c[k] && !check[i][j]) {
					dfs(i, j);
					ans[s]++;
				}
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// 1. 적록색약이 아닌 사람
	solve(0);

	// 2. 적록색약인 사람
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 'R') {
				a[i][j] = 'G';
			}
		}
	}
	solve(1);

	cout << ans[0] << ' ' << ans[1];
}