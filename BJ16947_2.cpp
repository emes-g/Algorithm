#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 3001;
vector<vector<int>> a;
bool check[MAX], finish[MAX];
int n, p, dist[MAX];

// <알고리즘>
// 1. 순환선 파악 (cycle detection)
// → 사이클을 구성하는 정점들을 알아내어, dist값을 0으로 설정한다.
// 2. 지선 파악   (bfs)
// → 사이클에 속하는 정점들을 queue에 삽입하여, dist값을 갱신한다.

// 간선의 개수와 정점의 개수가 같은 연결 그래프는 정확히 하나의 사이클만을 갖는다.

bool dfs(int x, int px) {
	check[x] = true;
	for (int next : a[x]) {
		if (!check[next]) {
			if (dfs(next, x)) {
				dist[next] = 0;
				if (next != p) {
					return true;
				}
				else {
					return false;
				}
			}
		}
		else if (!finish[next] && next != px) {
			p = next;	// dfs(p)까지 함수가 반환되면, 사이클에 해당하는 모든 정점을 찾았음을 의미
			dist[next] = 0;
			return true;
		}
	}
	finish[x] = true;
	return false;
}

void bfs() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (dist[i] == 0) {
			q.push(i);
			check[i] = true;
		}
	}
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int next : a[x]) {
			if (!check[next]) {
				check[next] = true;
				dist[next] = dist[x] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	a.resize(n + 1);
	for (int i = 0; i < n; i++) {
		int from, to;
		cin >> from >> to;
		a[from].push_back(to);
		a[to].push_back(from);
	}

	// 1. cycle detection
	memset(dist, -1, sizeof(dist));
	dfs(1, -1);

	// 2. bfs
	memset(check, false, sizeof(check));
	bfs();

	// 3. output
	for (int i = 1; i <= n; i++) {
		cout << dist[i] << ' ';
	}
}
