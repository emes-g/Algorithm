#include <iostream>
#include <vector>
using namespace std;
vector<int> a[1001];
int check[1001];

void dfs(int node) {
	check[node] = true;
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (!check[next]) {
			dfs(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		a[from].push_back(to);
		a[to].push_back(from);
	}

	// 2. solve (dfs)
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			dfs(i);
			ans++;
		}
	}

	// 3. output
	cout << ans;
	return 0;
}