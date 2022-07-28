#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1000;
bool a[MAX][MAX], check[MAX][MAX][10][2];
int n, m, k;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

// 변수
// b	해당 지점까지 가기 위해 부순 벽의 개수
// dist	해당 지점까지 가기 위한 최단 거리
// day	해당 지점에 도착했을 당시의 낮과 밤 상태

struct node {
	int x, y, b, dist;
	bool day;
	node(int x, int y, int b, int dist, bool day)
		:x(x), y(y), b(b), dist(dist), day(day){}
};

int bfs() {
	queue<node> q;
	q.push(node(0, 0, 0, 1, 1));
	check[0][0][0][1] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int b = q.front().b;
		int dist = q.front().dist;
		bool day = q.front().day;
		q.pop();
		if (x == n - 1 && y == m - 1) {
			return dist;
		}
		if (!check[x][y][b][!day]) {	// 대기
			check[x][y][b][!day] = true;
			q.push(node(x, y, b, dist + 1, !day));
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (a[nx][ny]) {	// 벽
					if (day && b < k && !check[nx][ny][b + 1][0]) {
						check[nx][ny][b + 1][0] = true;
						q.push(node(nx, ny, b + 1, dist + 1, 0));
					}
				}
				else {	// 땅
					if (!check[nx][ny][b][!day]) {
						check[nx][ny][b][!day] = true;
						q.push(node(nx, ny, b, dist + 1, !day));
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
	cin >> n >> m >> k;
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