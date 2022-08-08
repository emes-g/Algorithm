#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 10001;
typedef pair<int, int> pii;
int n, m, start, dest;
vector<pii> a[MAX];
bool check[MAX];

// <문제 분석>
// binary_search (결정 문제) + dfs/bfs (그래프 탐색)
// 결정 문제: 옮길 물품들의 중량이 mid여도 되는가?

// <주의 사항>
// 1. mid를 지정할 때마다, check를 초기화해줬어야 함.
// 2. 모든 정점을 한 번씩 방문하는 것이 그 의의이므로,
// dfs를 사용하든 bfs를 사용하든 상관 없어야 한다.

bool bfs(int mid) {
	queue<int> q;
	check[start] = true;
	q.push(start);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == dest) {
			return true;
		}
		for (pii next : a[x]) {
			if (!check[next.first] && next.second >= mid) {
				q.push(next.first);
				check[next.first] = true;
			}
		}
	}
	return false;
}

bool good(int mid) {
	memset(check, false, sizeof(check));
	return bfs(mid);
}

int binary_search(int left, int right) {
	while (left <= right) {
		int mid = (left + right) / 2;
		if (good(mid)) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return right;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	int right = 0;
	for (int i = 0; i < m; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		a[from].push_back({ to,weight });
		a[to].push_back({ from,weight });
		right = max(right, weight);
	}
	cin >> start >> dest;
	cout << binary_search(1, right);
}