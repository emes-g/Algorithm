#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
char a[50][50], check[50][50];
int r, c;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
struct node {
	int x, y, sec;
	node(int x, int y, int sec)
		:x(x), y(y), sec(sec) {}
};
queue<node> q;

// <변수 설명>
// check : 도치의 해당 칸 이동 여부
// sec
// ┕ 음수 : 이동하는 대상이 물이며 값은 항상 -1
// ┕ 양수 : 이동하는 대상이 도치이며 값은 해당 위치까지 이동하는 데 걸린 시간

// <코드 설명>
// 큐는 물과 고슴도치의 이동을 모두 담는다.
// 이를 구분하기 위해 sec이라는 변수가 필요하며, 
// 도치의 이동일 때 sec은 해당 위치까지 이동하는 데 걸린 시간으로 사용된다.

// <주의사항>
// 돌이 존재한다.
// 물은 반드시 1개가 존재하는 것은 아니다.
// ┕ 0개, 2개, 3개, ...

string bfs(int x1, int y1, int x2, int y2) {
	q.push(node(x2, y2, 0));
	check[x2][y2] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int sec = q.front().sec;
		q.pop();
		if (x == x1 && y == y1) {
			return to_string(sec);
		}
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
				if (sec == -1) {	// 물
					if (a[nx][ny] == '.') {
						a[nx][ny] = '*';
						q.push(node(nx, ny, -1));
					}
				}
				else {	// 고슴도치
					if ((a[nx][ny] == '.' || a[nx][ny] == 'D') && !check[nx][ny]) {
						check[nx][ny] = true;
						q.push(node(nx, ny, sec + 1));
					}
				}
			}
		}
	}
	return "KAKTUS";
}

int main() {
	int x1, y1, x2, y2;
	x1 = y1 = x2 = y2 = -1;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> a[i];
		for (int j = 0; j < c; j++) {
			if (a[i][j] == 'D') {	// 굴
				x1 = i;
				y1 = j;
			}
			else if (a[i][j] == '*') {	// 물
				q.push(node(i, j, -1));
			}
			else if (a[i][j] == 'S') {	// 고슴도치
				x2 = i;
				y2 = j;
			}
		}
	}
	cout << bfs(x1, y1, x2, y2);
}