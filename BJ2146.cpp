#include <iostream>
#include <utility>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 200;
int a[100][100];		// 바다와 육지 구분 (input)
int check[100][100];	// 연결 요소 파악
int dist[100][100];		// 섬 간 거리
pair<int, int> k[4]{
	{-1,0}, {1,0}, {0,-1}, {0,1}
};

// 1. 연결 요소를 구성하는 정점을 모두 파악한다.
void dfs(pair<int, int> node, int num, int n) {
	check[node.first][node.second] = num;
	for (int i = 0; i < 4; i++) {
		int x = node.first + k[i].first;
		int y = node.second + k[i].second;
		if (x >= 0 && x < n && y >= 0 && y < n) {
			if (a[x][y] == 1 && !check[x][y]) {
				dfs({ x,y }, num, n);
			}
		}
	}
}

// 2. 기준 섬(from)에서 다른 섬까지의 거리를 구한다.
int bfs(int from, int n) {
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				continue;
			}
			else if (check[i][j] == from) {
				q.push({ i,j });
				dist[i][j] = 0;
			}
		}
	}

	int ans = MAX;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = r + k[i].first;
			int y = c + k[i].second;
			if (x >= 0 && x < n && y >= 0 && y < n) {
				if (dist[x][y] >= 0) {	// 이미 방문한 점인 경우
					continue;
				}
				if (check[x][y] > 0) {	// 아직 방문하지 않았지만, 다른 섬에 해당하는 육지일 경우
					ans = dist[r][c];
					return ans;
				}
				dist[x][y] = dist[r][c] + 1;
				q.push({ x,y });
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1 && !check[i][j]) {
				dfs({ i,j }, ++num, n);
			}
		}
	}
	// 3. 과정 2를 반복하여 섬 간 거리의 최솟값을 찾아낸다.
	int ans = MAX;
	for (int i = 1; i < num; i++) {
		memset(dist, -1, sizeof(dist));
		ans = min(ans, bfs(i, n));
	}
	cout << ans;
}