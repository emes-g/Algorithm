#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
typedef tuple<int, int, int> t;
const int MAX = 100;
bool a[50][50], check[50][50];
int n, m, ans;
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

// <문제 파악>
// 모든 빈 칸에 대하여 안전 거리를 구하는 문제
// → 안전 거리가 최단 거리이므로 BFS 활용
// 시간복잡도 : O((NM)^2)

bool good(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}

int bfs(int x, int y) {
	memset(check, false, sizeof(check));
	queue<t> q;
	q.push({ x,y,0 });
	check[x][y] = true;
	while (!q.empty()) {
		int cnt;
		tie(x, y, cnt) = q.front();
		q.pop();
		if (a[x][y]) {
			return cnt;
		}
		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (good(nx, ny)) {
				if (!check[nx][ny]) {
					q.push({ nx,ny,cnt + 1 });
					check[nx][ny] = true;
				}
			}
		}
	}
	return MAX;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	// 2. solve (brute force & bfs)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!a[i][j]) {
				ans = max(ans, bfs(i, j));
			}
		}
	}
	cout << ans;
}