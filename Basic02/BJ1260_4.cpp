#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
vector<pair<int, int>> edges;
int cnt[1001];
bool check[1001];

// 간선 리스트로 구현한 dfs, bfs

void init() {
	fill_n(check, 1001, false);
	cout << '\n';
}

void dfs(int node) {
	check[node] = true;
	cout << node << ' ';
	for (int i = cnt[node - 1]; i < cnt[node]; i++) {
		int next = edges[i].second;
		if (!check[next]) {
			dfs(next);
		}
	}
}

void bfs(int node) {
	queue<int> q;
	check[node] = true;
	q.push(node);
	while (!q.empty()) {
		node = q.front();
		q.pop();
		cout << node << ' ';
		for (int i = cnt[node - 1]; i < cnt[node]; i++) {
			int next = edges[i].second;
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
		edges.push_back({ from, to });
		edges.push_back({ to, from });
	}
	sort(edges.begin(), edges.end());
	for (auto it = edges.begin(); it < edges.end(); it++) {
		cnt[it->first]++;
	}
	for (int i = 1; i <= n; i++) {
		cnt[i] += cnt[i - 1];
	}

	// 2. solve (dfs & bfs)
	dfs(v);
	init();
	bfs(v);
	return 0;
}