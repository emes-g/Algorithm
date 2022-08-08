#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int n, m, v, goal;
vector<vector<int>> a;
vector<bool> check;
vector<int> s;

// check one path(u,v) by using DFS
// DFS를 사용하여 정점 U에서 정점 V까지 가는 경로 하나 탐색

/*
input1
4 5 1 4
1 2
1 3
1 4
2 4
3 4

output1
1 2 4

input2
5 7 1 5
1 2
1 3 
1 4
2 3
2 4
3 5
4 5

output2
1 2 3 5
*/

void dfs(int x) {
	check[x] = true;
	s.push_back(x);
	if (x == goal) {	// 경로 출력
		for (int path : s) {
			cout << path << ' ';
		}
		cout << '\n';
		s.pop_back();
		return;
	}
	for (int next : a[x]) {
		if (!check[next]) {
			dfs(next);
			// check[next] = false;
		}
	}
	s.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	cin >> n >> m >> v >> goal;
	a.assign(n + 1, vector<int>());
	check.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		a[from].push_back(to);
		a[to].push_back(from);
	}

	// 2. solve
	for (int i = 1; i < n + 1; i++) {
		sort(a[i].begin(), a[i].end());
	}
	dfs(v);
}