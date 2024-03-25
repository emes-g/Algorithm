#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> t;
int n, m, ans = 64;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<t> cctv;

// <문제 파악>
// 사무실에 존재하는 모든 CCTV에 대하여 가능한 경우의 수를 세는 브루트 포스 문제
// 시간 복잡도 : O(NM * 4^8)

// <주의 사항>
// 매 level마다 만들어 놓은 cur을 통해 현재 사무실을 기억해 놓는 것이 중요하다. 
// → 복사 생성자를 이용한 deep copy

void observe(int x, int y, int dir, vector<vector<int>>& temp) {	// 해당 방향 감시
	int nx = x;
	int ny = y;
	while (true) {
		nx += dx[dir];
		ny += dy[dir];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (temp[nx][ny] > 0 && temp[nx][ny] < 6) {
				continue;
			}
			else if (temp[nx][ny] == 6) {
				break;
			}
			temp[nx][ny] = -1;
		}
		else {
			break;
		}
	}
}

void go(int level, vector<vector<int>> temp) {
	if (level == cctv.size()) {	// 모든 CCTV를 확인한 경우
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (temp[i][j] == 0) {
					cnt++;
				}
			}
		}
		ans = min(ans, cnt);
		return;
	}
	int x, y, type;
	tie(x, y, type) = cctv[level];
	vector<vector<int>> cur(temp);	// deep copy

	for (int k = 0; k < 4; k++) {
		observe(x, y, k, temp);
		switch (type) {
		case 2:
			if (k == 0) {
				observe(x, y, 1, temp);
			}
			else if (k == 1) {
				observe(x, y, 0, temp);
			}
			else if (k == 2) {
				observe(x, y, 3, temp);
			}
			else {
				observe(x, y, 2, temp);
			}
			break;
		case 3:
			if (k == 0) {
				observe(x, y, 3, temp);
			}
			else if (k == 1) {
				observe(x, y, 2, temp);
			}
			else if (k == 2) {
				observe(x, y, 0, temp);
			}
			else {
				observe(x, y, 1, temp);
			}
			break;
		case 4:
			if (k < 2) {
				observe(x, y, 2, temp);
				observe(x, y, 3, temp);
			}
			else {
				observe(x, y, 0, temp);
				observe(x, y, 1, temp);
			}
			break;
		case 5:
			for (int s = 0; s < 4; s++) {
				if (k != s) {
					observe(x, y, s, temp);
				}
			}
			break;
		}
		go(level + 1, temp);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp[i][j] = cur[i][j];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] > 0 && a[i][j] < 6) {
				cctv.push_back({ i,j,a[i][j] });
			}
		}
	}
	go(0, a);
	cout << ans;
}
