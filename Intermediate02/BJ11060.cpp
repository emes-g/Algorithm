#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1000;
int a[MAX], d[MAX];

void bfs() {
	fill(&d[0], &d[0] + MAX, MAX);
	queue<int> q;
	q.push(0);
	d[0] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 1; i <= a[x]; i++) {
			int next = x + i;
			if (next < MAX && d[next] > d[x] + 1) {
				q.push(next);
				d[next] = d[x] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// 1. input
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	// 2. solve
	bfs();
	
	// 3. output
	cout << (d[n - 1] == MAX ? -1 : d[n - 1]);
}
