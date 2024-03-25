#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1000;
bool a[MAX][MAX], check[MAX][MAX][2];
int n, m;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

// 7332KB/56MS

struct node {
	int x, y, dist, b;
	node(int x, int y, int dist, int b)
		:x(x), y(y), dist(dist), b(b) {}
};

int bfs() {
	queue<node> q;
	q.push(node(0, 0, 1, 0));
	check[0][0][0] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dist = q.front().dist;
		int b = q.front().b;
		q.pop();
		if (x == n - 1 && y == m - 1) {
			return dist;
		}
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (a[nx][ny]) {	// 벽
					if (!b && !check[nx][ny][1]) {
						check[nx][ny][1] = true;
						q.push(node(nx, ny, dist + 1, 1));
 					}
				}
				else {	// 땅
					if (!check[nx][ny][b]) {
						check[nx][ny][b] = true;
						q.push(node(nx, ny, dist + 1, b));
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			if (str[j] - '0') {
				a[i][j] = true;
			}
		}
	}

	// 2. solve
	cout << bfs();
}