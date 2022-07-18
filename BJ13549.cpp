#include <iostream>
#include <queue>
using namespace std;
const int MAX = 200000;
int dist[200000];

void bfs(int x, int k) {
	queue<int> q;
	q.push(x);
	dist[x] = 0;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		if (x + 1 >= 0 && x + 1 < MAX) {
			if (dist[x] + 1 < dist[x + 1]) {
				dist[x + 1] = dist[x] + 1;
				q.push(x + 1);
			}
		}
		if (x - 1 >= 0 && x - 1 < MAX) {
			if (dist[x] + 1 < dist[x - 1]) {
				dist[x - 1] = dist[x] + 1;
				q.push(x - 1);
			}
		}
		if (2 * x >= 0 && 2 * x < MAX) {
			if (dist[x] < dist[2 * x]) {
				dist[2 * x] = dist[x];
				q.push(2 * x);
			}
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	fill_n(dist, MAX, MAX);
	bfs(n, k);
	cout << dist[k];
	return 0;
}