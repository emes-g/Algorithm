#include <iostream>
#include <queue>
using namespace std;
char a[8][8], check[8][8];
int dx[8] = { -1,1,0,0,-1,-1,1,1 };
int dy[8] = { 0,0,-1,1,-1,1,-1,1 };
struct node {
	int x, y, obj;
	node(int x, int y, int obj)
		:x(x), y(y), obj(obj) {}
};

bool bfs(int wall) {
	queue<node> q;
	q.push(node(7, 0, 0));
	if (!wall) {
		check[7][0] = true;
	}
	for (int i = 7; i >= 0; i--) {
		for (int j = 0; j < 8; j++) {
			if (a[i][j] == '#') {
				q.push(node(i, j, 1));
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int obj = q.front().obj;
		q.pop();
		if (x == 0 && y == 7 && obj == 0) {
			return 1;
		}
		if (!obj) {	// 사람
			if (a[x][y] == '#') {
				continue;
			}
			else if (wall) {	// 제자리
				q.push(node(x, y, 0));
			}
			for (int k = 0; k < 8; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
					if (wall) {
						if (a[nx][ny] == '.') {
							q.push(node(nx, ny, 0));
						}
					}
					else {
						if (a[nx][ny] == '.' && !check[nx][ny]) {
							check[nx][ny] = true;
							q.push(node(nx, ny, 0));
						}
					}
				}
			}
		}
		else {	// 벽
			int nx = x + 1;
			a[x][y] = '.';
			if (nx < 8) {
				a[nx][y] = '#';
				q.push(node(nx, y, 1));
			}
			else {
				wall--;
			}
		}
	}
	return 0;
}

int main() {
	int wall = 0;
	for (int i = 0; i < 8; i++) {
		cin >> a[i];
		for (int j = 0; j < 8; j++) {
			if (a[i][j] == '#') {
				wall++;
			}
		}
	}
	cout << bfs(wall);
}
