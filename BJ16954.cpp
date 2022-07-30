#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
char a[8][8], check[8][8][9];
int dx[9] = { -1,1,0,0,-1,-1,1,1,0 };
int dy[9] = { 0,0,-1,1,-1,1,-1,1,0 };

// <핵심>
// 1. 8초 후에 모든 벽은 사라진다.
// 2. 같은 위치에 있더라도, 존재한 시간이 다르면 다른 정점이다.
// → check[x][y][t] 필요

int bfs() {
	queue<tuple<int, int, int>> q;
	q.push({ 7,0,0 });
	check[7][0][0] = true;
	while (!q.empty()) {
		int x, y, t;
		tie(x, y, t) = q.front();
		q.pop();
		if (x == 0 && y == 7) {
			return 1;
		}
		for (int k = 0; k < 9; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			int nt = min(t + 1, 8);
			if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8) {
				if (nx - t >= 0 && a[nx - t][ny] == '#') {	// 벽으로 이동한 경우 (불가능)
					continue;
				}
				else if (nx - nt >= 0 && a[nx - nt][ny] == '#') {	// 위에 벽이 있어서, 내가 이동한 후에 벽과 겹치는 경우 (불가능)
					continue;
				}
				else if (!check[nx][ny][nt]) {
					check[nx][ny][nt] = true;
					q.push({ nx,ny,nt });
				}
			}
		}
	}
	return 0;
}

int main() {
	for (int i = 0; i < 8; i++) {
		cin >> a[i];
	}
	cout << bfs();
}
