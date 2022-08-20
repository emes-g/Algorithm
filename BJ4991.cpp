#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int> t;
typedef pair<int, int> pii;
char a[20][20];
vector<pii> d;
int h, w, dist[11][11], check[20][20];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

// <문제 파악>
// 더러운 칸을 방문하는 순서를 지정하여,
// 각 더러운 칸 간 거리의 합이 최소가 되도록 구현
// → 순열 & BFS 활용
// 시간복잡도 : O(10! + 10*NM)

// <주의 사항>
// 1. 언뜻 보면 '아기 상어' 문제와 굉장히 유사하나 큰 차이점이 존재한다.
// '아기 상어'는 먹이를 먹는 순서가 우선순위에 따라 사전에 결정되어 있는 반면,
// '로봇 청소기'는 더러운 칸을 방문하는 순서가 정해져 있지 않아, 가능한 모든 경우를 해봐야 한다.

// 2. 더러운 칸의 위치는 고정되어 있으므로, 순열마다 BFS를 돌릴 필요가 없다.
// 순열에 앞서 각 더러운 칸 간 거리를 저장해놓으면 된다.

bool good(int x, int y) {
	return x >= 0 && x < h&& y >= 0 && y < w;
}

bool bfs(int x, int y, int idx) {
	// 1. BFS
	memset(check, -1, sizeof(check));
	queue<pii> q;
	q.push({ x,y });
	check[x][y] = 0;
	while (!q.empty()) {
		tie(x, y) = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (good(nx, ny)) {
				if (a[nx][ny] != 'x' && check[nx][ny] == -1) {
					q.push({ nx,ny });
					check[nx][ny] = check[x][y] + 1;
				}
			}
		}
	}

	// 2. 방문하지 못하는 더러운 칸이 존재하는 경우
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '*' && check[i][j] == -1) {
				return false;
			}
		}
	}

	// 3. 로봇 혹은 더러운 칸 간 거리를 구한다.
	for (int i = 0; i < d.size(); i++) {
		if (idx != i) {
			tie(x, y) = d[i];
			dist[idx][i] = check[x][y];
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true) {
		// 1. input
		int x, y;
		cin >> w >> h;
		if (w == 0 && h == 0) {
			break;
		}
		d.resize(1);
		for (int i = 0; i < h; i++) {
			cin >> a[i];
			for (int j = 0; j < w; j++) {
				if (a[i][j] == 'o') {
					x = i;
					y = j;
					d[0] = { x,y };
				}
				else if (a[i][j] == '*') {
					d.push_back({ i,j });
				}
			}
		}

		// 2. bfs
		bool ok = true;
		for (int i = 0; i < d.size(); i++) {
			tie(x, y) = d[i];
			if (!bfs(x, y, i)) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			cout << -1 << '\n';
			continue;
		}

		// 3. brute force (permutation)
		int ans = 400;
		vector<int> g;
		for (int i = 0; i < d.size(); i++) {
			g.push_back(i);
		}
		do {
			int sum = 0;
			for (int i = 1; i < g.size(); i++) {
				sum += dist[g[i - 1]][g[i]];
			}
			ans = min(ans, sum);

		} while (next_permutation(g.begin() + 1, g.end()));
		cout << ans << '\n';
	}
}