#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> a;
int check[3001], dist[3001];

// <각 역과 순환선 사이의 거리를 구해보자>
// 1. 순환선 -> DFS (사이클 찾고, 해당 사이클을 구성하는 정점 파악)
// 2. 각 역과 순환선 사이 최소 거리 -> basic BFS 

// <dfs return value>
// -2 : 이전 정점이 사이클에 포함되지 않는 경우
// -1 : 해당 그래프에 사이클이 존재하지 않는 경우
// 0 ~ n : 이전 정점이 사이클에 포함되는 경우

// <check value>
// 2 : 순환선 내 정점
// 1 : 지선 내 정점
// 0 : 사이클을 찾는 과정에서 미방문한 정점

int dfs(int cur, int prev) {
	if (check[cur] == 1) {
		return cur;
	}
	check[cur] = 1;
	for (int next : a[cur]) {
		if (next != prev) {
			int res = dfs(next, cur);
			if (res == -2) {	// 현재 정점이 사이클에 포함되지 않는 경우
				return -2;
			}
			else if (res >= 0) {	// 현재 정점이 사이클에 포함되는 경우
				check[cur] = 2;
				if (res == cur) {	// 사이클의 시작점
					return -2;
				}
				else {
					return res;
				}
			}
		}
	}
	return -1;	// 해당 그래프에서 사이클을 찾지 못한 경우
}

void bfs(int n) {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (check[i] == 2) {	// 순환선 내 정점
			dist[i] = 0;
			q.push(i);
		}
		else {	// 지선 내 정점
			dist[i] = -1;
		}
	}
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int next : a[x]) {
			if (dist[next] == -1) {
				dist[next] = dist[x] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n;
	cin >> n;
	a.assign(n + 1, vector<int>());
	for (int i = 0; i < n; i++) {
		int from, to;
		cin >> from >> to;
		a[from].push_back(to);
		a[to].push_back(from);
	}

	// 2. solve (dfs & bfs)
	dfs(1, 0);
	bfs(n);

	// 3. output
	for (int i = 1; i <= n; i++) {
		cout << dist[i] << ' ';
	}
	return 0;
}
