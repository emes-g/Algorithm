#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
const int MAX = 1000;
bool a[MAX][MAX], check[MAX][MAX][2];
int n, m;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int bfs() {
	queue<tuple<int, int, int, int>> q;
	q.push({ 0,0,1,0 });
	check[0][0][0] = true;
	while (!q.empty()) {
		int x, y, dist, b;
		tie(x, y, dist, b) = q.front();
		q.pop();
		if (x == n - 1 && y == m - 1) {
			return dist;
		}
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (a[nx][ny]) {	// 벽
					if (b < 1 && !check[nx][ny][1]) {
						check[nx][ny][1] = true;
						q.push({ nx,ny,dist + 1,1 });
					}
				}
				else {
					if(!check[nx][ny][b]) {
						check[nx][ny][b] = true;
						q.push({ nx,ny,dist + 1,b });
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
	cout << bfs();
}