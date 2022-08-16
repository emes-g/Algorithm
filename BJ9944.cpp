#include <iostream>
#include <vector>
using namespace std;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, m, ans = 1e6;
vector<vector<bool>> a;

// <문제 파악>
// 상태 복구가 필요한 브루트 포스

// <주의 사항>
// 1. 이동하지 못한 경우에는 다음 레벨로 가지 않는다.
// 2. go(level == 0)를 호출하기 전, 해당 위치를 check하고 호출한다. 

bool good(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}

void go(int level, int x, int y, int blank) {
	if (blank == 0) {
		ans = min(ans, level);
		return;
	}
	for (int k = 0; k < 4; k++) {
		int nx = x;
		int ny = y;
		while (true) {
			nx += dx[k];
			ny += dy[k];
			if (good(nx, ny) && !a[nx][ny]) {
				a[nx][ny] = true;
				blank--;
			}
			else {
				nx -= dx[k];
				ny -= dy[k];
				break;
			}
		}
		if (!(x == nx && y == ny)) {	// 이동하지 못한 경우에는 다음 레벨로 가지 않는다.
			go(level + 1, nx, ny, blank);
		}
		while (!(x == nx && y == ny)) {	// 상태 복구
			a[nx][ny] = false;
			blank++;
			nx -= dx[k];
			ny -= dy[k];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while (cin >> n >> m) {
		ans = 1e6;
		a.assign(n, vector<bool>(m));
		int blank = 0;
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < m; j++) {
				if (str[j] == '*') {
					a[i][j] = true;
				}
				else {
					blank++;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!a[i][j]) {
					a[i][j] = true;
					go(0, i, j, blank - 1);
					a[i][j] = false;	// 상태 복구
				}
			}
		}
		cout << "Case " << t++ << ": " << (ans == 1e6 ? -1 : ans) << '\n';
	}
}