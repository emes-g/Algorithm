#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
int n, m, a[20][20], ans;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool check[20][20];

// <알고리즘>
// 1. 바둑돌 2개를 둘 위치 선정	(브루트 포스)
// 2. 이후, 죽일 수 있는 상대 돌 개수를 확인 (DFS/BFS)
// 3. 최댓값이면 갱신
// 시간 복잡도 : O((NM)^3)

int bfs() {
	memset(check, false, sizeof(check));
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 2 && !check[i][j]) {	// 한 그룹당 한 번씩
				queue<pair<int, int>> q;
				q.push({ i,j });
				check[i][j] = true;
				bool ok = true;
				int cnt = 1;
				while (!q.empty()) {
					int x, y;
					tie(x, y) = q.front();
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
							if (a[nx][ny] == 0) {	// 빈틈없이 에워싸지 못한 경우
								ok = false;
								continue;
							}
							else if (a[nx][ny] == 2 && !check[nx][ny]) {
								q.push({ nx,ny });
								check[nx][ny] = true;
								cnt++;
							}
						}
					}
				}
				if (ok) {
					sum += cnt;
				}
			}
		}
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	// 1. 돌 2개 두기 → O((NM)^2)
	for (int x1 = 0; x1 < n; x1++) {
		for (int y1 = 0; y1 < m; y1++) {
			if (a[x1][y1] == 0) {
				a[x1][y1] = 1;
				for (int x2 = 0; x2 < n; x2++) {
					for (int y2 = 0; y2 < m; y2++) {
						if (a[x2][y2] == 0) {
							a[x2][y2] = 1;
							ans = max(ans, bfs());	// 2. 죽일 수 있는 상대 돌 개수 파악하기 → O(NM)
							a[x2][y2] = 0;
						}
					}
				}
				a[x1][y1] = 0;
			}
		}
	}
	cout << ans;
}