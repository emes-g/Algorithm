#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n, m, ans, a[8][8];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool check[8][8];

// 시간복잡도 : O((NM)^4)
// 1. 벽을 3개 세운다	→ O((NM)^3)
// 2. 안전 영역의 크기를 구한다	→ O(NM)

int bfs() {
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 2) {
				q.push({ i,j });
				check[i][j] = true;
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (!a[nx][ny] && !check[nx][ny]) {
					check[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
	int size = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!a[i][j] && !check[i][j]) {
				size++;
			}
		}
	}
	return size;
}

void go(int level, int x, int y) {
	if (level == 3) {
		ans = max(ans, bfs());
		memset(check, false, sizeof(check));
		return;
	}
	if (x == n) {
		return;
	}
	else if (y == m) {
		go(level, x + 1, 0);
		return;
	}
	else if (a[x][y]) {
		go(level, x, y + 1);
		return;
	}
	a[x][y] = 1;
	go(level + 1, x, y + 1);
	a[x][y] = 0;
	go(level, x, y + 1);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	go(0, 0, 0);
	cout << ans;
}