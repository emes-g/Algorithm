#include <iostream>
#include <queue>
using namespace std;
int a[101], dist[101];

void bfs() {
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (a[x]) {	// 해당 칸에 뱀이나 사다리가 있는 경우
			if (!dist[a[x]] || dist[a[x]] > dist[x]) {
				q.push(a[x]);
				dist[a[x]] = dist[x];
			}
			continue;
		}
		for (int i = 1; i <= 6; i++) {
			int next = x + i;
			if (next > 100) {
				break;
			}
			if (!dist[next] || dist[next] > dist[x] + 1) {
				q.push(next);
				dist[next] = dist[x] + 1;
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		int from, to;
		cin >> from >> to;
		a[from] = to;
	}
	bfs();
	cout << dist[100];
}