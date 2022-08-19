#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef pair<int, int> pii;
vector<string> a;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int r, c;

void bfs() {
	// 1. 양의 위치를 모두 담는다.
	queue<pii> q;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j] == 'S') {
				q.push({ i,j });
			}
		}
	}

	// 2. 양의 주변에 울타리를 설치해준다.
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
				if (a[nx][ny] == 'W') {
					cout << 0;
					return;
				}
				else if (a[nx][ny] == '.') {
					a[nx][ny] = 'D';
				}
			}
		}
	}

	cout << 1 << '\n';
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << a[i][j];
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> r >> c;
	a.resize(r);
	for (int i = 0; i < r; i++) {
		cin >> a[i];
	}
	bfs();
}