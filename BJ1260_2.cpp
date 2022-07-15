#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
bool check[1001];
vector<int> a[1001];

// 인접 리스트로 구현한 dfs, bfs

void init() {
	fill_n(check, 1001, false);
	cout << '\n';
}

void dfs(int node, int n) {	// 재귀
	check[node] = true;
	cout << node << ' ';
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (!check[next]) {
			dfs(next, n);
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
		for (int i = 0; i < a[node].size(); i++) {
			int next = a[node][i];
			if (!check[next]) {
				check[next] = true;
				q.push(next);
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
		a[from].push_back(to);
		a[to].push_back(from);
	}
	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}

	// 2. solve (dfs & bfs)
	dfs(v, n);
	init();
	bfs(v, n);
	return 0;
}
