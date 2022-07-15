#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a[20001];
int color[20001];

void init(int v) {
	for (int i = 1; i <= v; i++) {
		a[i].clear();
		color[i] = 0;
	}
}

bool dfs(int node, int c) {
	color[node] = c;
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (color[next] == c) {
			return false;
		}
		else if (color[next] == 0) {
			if (!dfs(next, -c)) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int k;
	cin >> k;
	while (k--) {
		// 1. input
		int v, e;
		cin >> v >> e;
		for (int i = 0; i < e; i++) {
			int from, to;
			cin >> from >> to;
			a[from].push_back(to);
			a[to].push_back(from);
		}

		// 2. solve (dfs)
		bool ok = true;
		for (int i = 1; i <= v; i++) {
			if (color[i] == 0) {
				if (!dfs(i, 1)) {
					ok = false;
					break;
				}
			}
		}

		// 3. output
		cout << (ok ? "YES\n" : "NO\n");
		init(v);
	}
}