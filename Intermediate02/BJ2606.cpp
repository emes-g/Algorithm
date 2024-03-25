#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> a[101];
bool check[101];

int bfs() {
	int ans = -1;
	queue<int> q;
	q.push(1);
	check[1] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		ans++;
		for (int next : a[x]) {
			if (!check[next]) {
				q.push(next);
				check[next] = true;
			}
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	cout << bfs();
}
