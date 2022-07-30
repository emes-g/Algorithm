#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
char a[8][8], check[8][8][9];
int dx[9] = { -1,1,0,0,-1,-1,1,1,0 };
int dy[9] = { 0,0,-1,1,-1,1,-1,1,0 };

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
				if (nx - t >= 0 && a[nx - t][ny] == '#') {
					continue;
				}
				else if (nx - nt >= 0 && a[nx - nt][ny] == '#') {
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