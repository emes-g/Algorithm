#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<vector<int>> a;
vector<int> order;
vector<bool> check;
int n;
// input
// 4
// 1 2
// 1 3
// 2 4
// 1 4 2 3

// 정렬된 연결 리스트
// 1 : 3 2
// 2 : 1 4
// 3 : 1
// 4 : 2

// order : 입력 순서대로 최대한 탐색하기 위해, 해당 노드들이 와야 하는 자리
// ==> n번 노드가 몇 번째에 와야 하는지
// order[1] : 1번 노드가 와야 하는 자리 (1)
// order[4] : 4번 노드가 와야 하는 자리 (2)
// order[2] : 2번 노드가 와야 하는 자리 (3)
// order[3] : 3번 노드가 와야 하는 자리 (4)

bool bfs() {
	queue<int> q;
	q.push(1);
	check[1] = true;
	int idx = 2;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int next : a[x]) {
			if (!check[next]) {
				if (order[next] == idx) {	// 다음에 오는 숫자가 idx번째 자리에 올 숫자가 맞는 경우
					q.push(next);
					check[next] = true;
					idx++;
				}
				else {	// 다음에 오는 숫자가 idx번째 자리에 올 숫자가 아닌 경우
					return false;
				}
			}
		}
	}
	return true;
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

	// 2. solve (bfs)
	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end(), [](auto x, auto y) {
			return order[x] < order[y];
			});
	}
	check.resize(n + 1);
	cout << bfs();
}
