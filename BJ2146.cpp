#include <iostream>
#include <utility>
#include <queue>
using namespace std;
const int MAX = 200;
int a[100][100];		// 바다와 육지 구분 (input)
int check[100][100];		// 연결 요소 파악
int dist[100][100];		// 섬 간 거리
pair<int, int> k[4]{
	{-1,0}, {1,0}, {0,-1}, {0,1}
};

// <변경점>
// 기존 : 기준 섬에서 다른 모든 섬들을 방문하는 과정을 그룹 수만큼 반복
// 신규 : 기준 섬을 특정하지 않고, bfs를 1회만 실행
// (다리를 놓을 수 있는 상황 : 그룹을 늘려가다가, 다른 그룹과 마주치는 경우)

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

int bfs(int n) {
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j]) {	// 육지라면
				q.push({ i,j });
				dist[i][j] = 0;
			}
			else {	// 바다라면
				dist[i][j] = -1;
			}
		}
	}

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = r + k[i].first;
			int y = c + k[i].second;
			if (x >= 0 && x < n && y >= 0 && y < n) {
				if (dist[x][y] < 0) {
					dist[x][y] = dist[r][c] + 1;
					check[x][y] = check[r][c];		// 그룹 확장
					q.push({ x,y });
				}
			}
		}
	}

	int ans = MAX;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int s = 0; s < 4; s++) {
				int x = i + k[s].first;
				int y = j + k[s].second;
				if (x >= 0 && x < n && y >= 0 && y < n) {
					if (check[x][y] != check[i][j]) {	// 다른 그룹간 마주친 경우
						ans = min(ans, dist[x][y] + dist[i][j]);
					}
				}
			}
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	// 2. solve (dfs & bfs)
	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1 && !check[i][j]) {
				dfs({ i,j }, ++num, n);
			}
		}
	}
	cout << bfs(n);
}
