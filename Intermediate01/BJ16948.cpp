#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n, dist[200][200];
int dx[6] = { -2,-2,0,0,2,2 };
int dy[6] = { -1,1,-2,2,-1,1 };

int bfs(int x, int y, int r2, int c2) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	dist[x][y] = 0;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (x == r2 && y == c2) {
			return dist[r2][c2];
		}
		for (int k = 0; k < 6; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (dist[nx][ny] == -1) {
					dist[nx][ny] = dist[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
	return -1;
}

int main() {
	int r1, c1, r2, c2;
	cin >> n >> r1 >> c1 >> r2 >> c2;
	memset(dist, -1, sizeof(dist));
	cout << bfs(r1, c1, r2, c2);
}