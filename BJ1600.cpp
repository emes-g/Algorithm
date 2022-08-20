#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef tuple<int, int, int, int> t;
bool a[200][200], check[200][200][30];
int k, h, w;
int dx[12] = { -2,-2,-1,-1,1,1,2,2,-1,1,0,0 };
int dy[12] = { -1,1,-2,2,-2,2,-1,1,0,0,-1,1 };

// <문제 파악>
// '벽 부수고 이동하기 2'와 유사한 문제 (14442)
// 시간복잡도 : O(NMK)

// <주의 사항>
// 처음부터 K번 말처럼 점프하는 것이 아니라, 원할 때 하는 것임.

bool good(int x, int y) {
	return x >= 0 && x < h&& y >= 0 && y < w;
}

bool bfs() {
	queue<t> q;
	q.push({ 0,0,0,0 });
	check[0][0][0] = true;
	while (!q.empty()) {
		int x, y, cnt, use;
		tie(x, y, cnt, use) = q.front();
		q.pop();
		if (x == h - 1 && y == w - 1) {
			cout << cnt;
			return true;
		}
		else if (use < k) {
			for (int s = 0; s < 12; s++) {
				int nx = x + dx[s];
				int ny = y + dy[s];
				if (good(nx, ny)) {
					int u = (s < 8 ? use + 1 : use);
					if (!a[nx][ny] && !check[nx][ny][u]) {
						q.push({ nx,ny,cnt+1,u });
						check[nx][ny][u] = true;
					}
				}
			}
		}
		else {
			for (int s = 8; s < 12; s++) {
				int nx = x + dx[s];
				int ny = y + dy[s];
				if (good(nx, ny)) {
					if (!a[nx][ny] && !check[nx][ny][use]) {
						q.push({ nx,ny,cnt+1,use });
						check[nx][ny][use] = true;
					}
				}
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	cin >> k >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
		}
	}

	// 2. solve (bfs)
	if (!bfs()) {
		cout << -1;
	}
}