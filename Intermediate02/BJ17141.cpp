#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef pair<int, int> pii;
const int MAX = 2500;
int n, m, ans = MAX;
int a[50][50], d[50][50], active[10];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<pii> virus;

// <문제 파악> 
// 바이러스를 놓을 위치를 m개 선택하여 BFS 수행

int bfs() {
	fill(&d[0][0], &d[0][0] + 50 * 50, MAX);
	queue<pii> q;
	for (int i = 0; i < m; i++) {	// 바이러스 배치
		int x, y;
		tie(x, y) = virus[active[i]];
		q.push({ x,y });
		a[x][y] = 2;
		d[x][y] = 0;
	}
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (a[nx][ny] != 1 && d[nx][ny] > d[x][y] + 1) {
					d[nx][ny] = d[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
	for (int i = 0; i < m; i++) {	// 상태 복구
		int x, y;
		tie(x, y) = virus[active[i]];
		a[x][y] = 0;
	}

	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0) {
				ret = max(ret, d[i][j]);
			}
		}
	}
	return ret;
}

void go(int level, int index) {
	if (level == m) {
		ans = min(ans, bfs());
		return;
	}
	else if (index >= virus.size()) {
		return;
	}
	active[level] = index;
	go(level + 1, index + 1);
	go(level, index + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 2) {
				a[i][j] = 0;
				virus.push_back({ i,j });
			}
		}
	}
	
	// 2. solve (선택 & bfs)
	go(0, 0);
	cout << (ans == MAX ? -1 : ans);
}