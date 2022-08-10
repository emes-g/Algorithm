#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> a;
vector<bool> check, finish;
int n, m;

// 가장 기본적인 cycle detecion 형태 (back edge)

// input
// 3 3
// 1 2
// 2 3
// 3 1

void dfs(int x) {
	check[x] = true;
	for (int next : a[x]) {
		if (!check[next]) {
			dfs(next);
		}
		else if (!finish[next]) {
			cout << "cycle detection\n";
		}
	}
	finish[x] = true;
}

int main() {
	cin >> n >> m;
	a.resize(n + 1);
	check.resize(n + 1);
	finish.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		a[from].push_back(to);
	}
	dfs(1);
}