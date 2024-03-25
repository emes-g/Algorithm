#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> a;
vector<int> order;
vector<bool> check;
int n, idx = 1;

// <문제 파악>
// 특정한 순서를 기억해서 진행해야 하는 DFS

// <주의 사항>
// 현재 위치에서 갈 수 있는 곳을 모두 넣는 BFS와 달리,
// DFS는 최대한 깊게 들어가다가 더 이상 들어갈 공간이 없으면 돌아온다.
// → for문이 끝났다고 true를 반환하면 답이 아닌데 답이라고 오인할 수 있음에 주의
void dfs(int x) {
	check[x] = true;
	idx++;
	for (int next : a[x]) {
		if (!check[next]) {
			if (order[next] == idx) {
				dfs(next);
			}
		}
	}
	// return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	cin >> n;
	a.resize(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int from, to;
		cin >> from >> to;
		a[from].push_back(to);
		a[to].push_back(from);
	}
	order.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		order[x] = i;
	}

	// 2. solve (dfs)
	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end(), [](auto x, auto y) {
			return order[x] < order[y];
			});
	}
	check.resize(n + 1);
	dfs(1);
	cout << (idx == n + 1);
}
