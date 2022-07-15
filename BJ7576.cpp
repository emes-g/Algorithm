#include <iostream>
#include <utility>
#include <queue>
using namespace std;
int a[1000][1000], dis[1000][1000];
pair<int, int> k[4]{
	{0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

int bfs(int n, int m) {
	// 1. 익은 토마토는 다 큐에 넣는다.
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1) {
				q.push({ i,j });
			}
		}
	}
	if (q.size() == n * m) {
		return 0;
	}

	// 2. bfs
	while (!q.empty()) {
		auto node = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = node.first + k[i].first;
			int y = node.second + k[i].second;
			if (x >= 0 && x < n && y >= 0 && y < m) {
				if (a[x][y] == 0) {
					q.push({ x,y });
					a[x][y] = 1;
					dis[x][y] = dis[node.first][node.second] + 1;
				}
			}
		}
	}

	// 3. 토마토가 모두 익지 못하는 상황을 검사한다.
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				return -1;
			}
			else {
				cnt = max(cnt, dis[i][j]);
			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n, m;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	
	// 2. bfs
	cout << bfs(n, m);
	return 0;
}