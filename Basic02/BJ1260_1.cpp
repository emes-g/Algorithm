#include <iostream>
#include <queue>
using namespace std;
bool a[1001][1001], check[1001];

// 인접 행렬로 구현한 dfs, bfs

void init() {
	fill_n(check, 1001, false);
	cout << '\n';
}

void dfs(int node, int n) {	// 재귀
	check[node] = true;
	cout << node << ' ';
	for (int i = 1; i <= n; i++) {
		if (a[node][i] && !check[i]) {
			dfs(i, n);
		}
	}
}

void bfs(int node, int n) {
	queue<int> q;
	check[node] = true;
	q.push(node);
	while (!q.empty()) {
		node = q.front();
		q.pop();
		cout << node << ' ';
		for (int i = 1; i <= n; i++) {
			if (a[node][i] && !check[i]) {
				check[i] = true;
				q.push(i);
			}
		}
	}
}

int main() {
	// 1. input
	int n, m, v;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		a[from][to] = a[to][from] = true;
	}

	// 2. solve (dfs & bfs)
	dfs(v, n);
	init();
	bfs(v, n);
	return 0;
}