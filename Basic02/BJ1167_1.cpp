#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 100001;
vector<vector<pair<int, int>>> a;
int dist[MAX];

void bfs(int node) {
	fill_n(dist, MAX, -1);
	queue<int> q;
	q.push(node);
	dist[node] = 0;
	while (!q.empty()) {
		node = q.front();
		q.pop();
		for (auto next : a[node]) {
			if (dist[next.first] == -1) {
				q.push(next.first);
				dist[next.first] = dist[node] + next.second;
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
	a.assign(n + 1, vector<pair<int, int>>());
	for (int i = 0; i < n; i++) {
		int from, to, weight;
		cin >> from;
		while (true) {
			cin >> to;
			if (to == -1) {
				break;
			}
			cin >> weight;
			a[from].push_back({ to,weight });
			a[to].push_back({ from,weight });
		}
	}

	// 2. solve (bfs)
	// (1) 임의의 정점에서 가장 먼 정점(u)을 찾는다.
	bfs(1);
	int u = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[u] < dist[i]) {
			u = i;
		}
	}
	// (2) u에서 가장 먼 정점(v)을 찾는다.
	bfs(u);

	// 3. output
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dist[i]);
	}
	cout << ans;
}