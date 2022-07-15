#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 200000;
bool check[MAX];
int dis[MAX];

// if MAX = 10만, 반례 -> 50000 99999
// ans : 2
// output : 3

void bfs(int x, int k) {
	queue<int> q;
	q.push(x);
	check[x] = true;
	dis[x] = 0;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		int next[3] = { x + 1, x - 1, 2 * x };
		for (int i = 0; i < 3; i++) {
			if (next[i] >= 0 && next[i] < MAX && !check[next[i]]) {
				q.push(next[i]);
				check[next[i]] = true;
				dis[next[i]] = dis[x] + 1;
			}
		}
		if (check[k]) {
			return;
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	bfs(n, k);
	cout << dis[k];
	return 0;
}