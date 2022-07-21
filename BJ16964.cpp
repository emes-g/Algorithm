#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100001;
vector<vector<int>> a;
vector<int> order;
bool check[MAX];
int idx = 2;

void dfs(int x) {
	check[x] = true;
	for (int next : a[x]) {
		if (check[next]) {
			continue;
		}
		if (order[next] == idx) {
			idx++;
			dfs(next);
		}
	}
}

int main() {
	// 1. input
	int n;
	cin >> n;
	a.assign(n + 1, vector<int>());
	for (int i = 0; i < n - 1; i++) {
		int from, to;
		cin >> from >> to;
		a[from].push_back(to);
		a[to].push_back(from);
	}
	order.assign(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		order[x] = i;
	}

	// 2. solve (dfs)
	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end(), [](int x, int y) {
			return order[x] < order[y];
			});
	}
	dfs(1);
	cout << (idx == n + 1);
}