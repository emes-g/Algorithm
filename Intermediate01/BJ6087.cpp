#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
char a[100][100];
int h, w, dist[100][100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

// 거리는 일일이 노드에 저장할 필요가 없습니다.

struct node {
	int x, y, prev;
	node(int x, int y, int prev)
		:x(x), y(y), prev(prev){}
};

void bfs(int x1, int y1, int x2, int y2) {
	queue<node> q;
	q.push(node(x1, y1, -1));
	dist[x1][y1] = 0;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int prev = q.front().prev;
		q.pop();
		if (x == x2 && y == y2) {
			cout << dist[x2][y2];
			return;
		}
		for (int k = 0; k < 4; k++) {
			int nx = x, ny = y;
			while (true) {
				nx += dx[k];
				ny += dy[k];
				if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
					if (a[nx][ny] == '*') {
						break;
					}
					if (dist[nx][ny] == -1) {
						if (prev == -1) {
							dist[nx][ny] = 0;
						}
						else if ((prev < 2 && k >= 2) || (prev >= 2 && k < 2)) {
							dist[nx][ny] = dist[x][y] + 1;
						}
						else {
							dist[nx][ny] = dist[x][y];
						}
						q.push(node(nx, ny, k));
					}
				}
				else {
					break;
				}
			}
		}
	}
}

int main() {
	cin >> w >> h;
	int x1, y1, x2, y2;
	x1 = y1 = x2 = y2 = -1;
	for (int i = 0; i < h; i++) {
		cin >> a[i];
		for (int j = 0; j < w; j++) {
			if (a[i][j] == 'C') {
				if (x1 == -1) {
					x1 = i;
					y1 = j;
				}
				else {
					x2 = i;
					y2 = j;
				}
			}
		}
	}
	memset(dist, -1, sizeof(dist));
	bfs(x1,y1,x2,y2);
}