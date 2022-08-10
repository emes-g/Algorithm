#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
char a[50][50];
bool check[50][50];
int n, m;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

// <문제 파악>
// 격자 형식의 cycle detection

// 직전에 방문했던 정점으로 가지만 않는다면,
// 크기가 4이상인 cycle이 보장됨.

bool dfs(int x, int y, int px, int py) {
	if (check[x][y]) {	// 방문했던 점에 재방문한 경우
		return true;
	}
	check[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (a[nx][ny] == a[x][y]) {
				if (!(px == nx && py == ny)) {	// 직전에 방문한 정점으로는 가지 않는다.
					if (dfs(nx, ny, x, y)) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

int main() {
	// 1. input
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// 2. solve (dfs)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!check[i][j]) {
				if (dfs(i, j, -1, -1)) {
					cout << "Yes";
					return 0;
				}
			}
		}
	}
	cout << "No";
}
