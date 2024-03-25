#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
bool check[50][50];
int n, m, a[50][50], g[50][50];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };

// <문제 파악>
// bitmask를 사용하는 bfs 문제이다.
// 각 연결요소를 구성하는 요소들과 그 크기를 bfs로 사전에 구해놓고,
// 모든 점에 대하여 완전탐색하는 방식

bool good(int x, int y) {
	return x >= 0 && x < m&& y >= 0 && y < n;
}

int bfs(int x, int y, int num) {
	int size = 1;
	queue<pair<int, int>> q;
	q.push({ x,y });
	check[x][y] = true;
	g[x][y] = num;
	while (!q.empty()) {
		tie(x, y) = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (good(nx, ny) && !check[nx][ny]) {
				if (!(a[x][y] & (1 << k))) {
					q.push({ nx,ny });
					check[nx][ny] = true;
					g[nx][ny] = num;
					size++;
				}
			}
		}
	}
	return size;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	// 2. solve (bfs & bitmask)
	vector<int> gs(1);
	int ans1 = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				int size = bfs(i, j, gs.size());
				gs.push_back(size);
				ans1 = max(ans1, size);
			}
		}
	}
	cout << gs.size() - 1 << '\n';
	cout << ans1 << '\n';

	int ans3 = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (good(nx, ny) && g[nx][ny] != g[i][j]) {
					ans3 = max(ans3, gs[g[nx][ny]] + gs[g[i][j]]);
				}
			}
		}
	}
	cout << ans3;
}