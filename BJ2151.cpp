#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
const int MAX = 2500;
typedef tuple<int, int, int> t;
string a[50];
int n, visit[50][50][4];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

// <문제 파악>
// 한 번 정점한 방문은 다시 방문하지 않는 전형적인 BFS 문제

// <주의 사항>
// cstring::memset
// byte 단위로 값을 초기화하는 것이지, 배열 초기화 용도로 사용하는 함수가 아니다.
// 배열을 초기화할 때는 std::fill을 활용하자.

bool good(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < n;
}

void bfs(int x1, int y1, int x2, int y2) {
	fill(&visit[0][0][0], &visit[0][0][0] + 50 * 50 * 4, MAX);
	queue<t> q;
	for (int k = 0; k < 4; k++) {
		q.push({ x1,y1,k });
		visit[x1][y1][k] = 0;
	}
	while (!q.empty()) {
		int x, y, dir;
		tie(x, y, dir) = q.front();
		q.pop();
		if (x == x2 && y == y2) {
			continue;
		}
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (good(nx, ny)) {
			if (a[nx][ny] != '*') {
				if (visit[nx][ny][dir] > visit[x][y][dir]) {
					visit[nx][ny][dir] = visit[x][y][dir];
					q.push({ nx,ny,dir });
				}
			}
			if (a[nx][ny] == '!') {
				int d[2];
				if (dir < 2) {
					d[0] = 2;
					d[1] = 3;
				}
				else {
					d[0] = 0;
					d[1] = 1;
				}
				for (int k = 0; k < 2; k++) {
					if (visit[nx][ny][d[k]] > visit[x][y][dir] + 1) {
						visit[nx][ny][d[k]] = visit[x][y][dir] + 1;
						q.push({ nx,ny,d[k] });
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int x1, y1, x2, y2;
	x1 = y1 = x2 = y2 = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < n; j++) {
			if (a[i][j] == '#') {
				if (x1 == -1) {
					x1 = i;
					y1 = j;
				}
				else {
					x2 = i;
					y2 = j;
				}
			}
		}
	}

	// 2. bfs
	bfs(x1, y1, x2, y2);

	// 3. output
	int ans = MAX;
	for (int k = 0; k < 4; k++) {
		ans = min(ans, visit[x2][y2][k]);
	}
	cout << ans;
}