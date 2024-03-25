#include <iostream>
#include <utility>
#include <queue>
using namespace std;
int a[100][100], dis[100][100];
bool check[100][100];
pair<int, int> k[4]{
	{0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

void bfs(pair<int, int> node, int n, int m) {
	queue<pair<int, int>> q;
	q.push(node);
	dis[node.first][node.second] = 1;
	while (!q.empty()) {
		node = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x = node.first + k[i].first;
			int y = node.second + k[i].second;
			if (x >= 0 && x < n && y >= 0 && y < m) {
				if (a[x][y] == 1 && !check[x][y]) {
					q.push({ x, y });
					check[x][y] = true;
					dis[x][y] = dis[node.first][node.second] + 1;
				}
			}
		}
	}
}

int main() {
	// 1. input
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			a[i][j] = str[j] - '0';
		}
	}

	// 2. solve (bfs)
	bfs({ 0, 0 }, n, m);

	// 3. output
	cout << dis[n - 1][m - 1];
	return 0;
}
