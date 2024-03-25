#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef pair<int, int> pii;
vector<vector<int>> a;
int n, m, ans;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

// 시간복잡도 : O(NM)

bool good(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}

int bfs(int x, int y, int val) {
	int size = 1;
	queue<pii> q;
	q.push({ x,y });
	a[x][y] = val;
	while (!q.empty()) {
		tie(x, y) = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (good(nx, ny)) {
				if (a[nx][ny] == -1) {
					q.push({ nx,ny });
					a[nx][ny] = val;
					size++;
				}
			}
		}
	}
	return size;
}

bool good2(int x, int y) {
	for (int k1 = 0; k1 < 3; k1++) {
		int nx1 = x + dx[k1];
		int ny1 = y + dy[k1];
		if (good(nx1, ny1)) {
			for (int k2 = k1 + 1; k2 < 4; k2++) {
				int nx2 = x + dx[k2];
				int ny2 = y + dy[k2];
				if (good(nx2, ny2)) {
					int g1 = a[nx1][ny1];
					int g2 = a[nx2][ny2];
					if (g1 != g2 && g1 * g2 != 0) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	a.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
			a[i][j] = num * -1;
		}
	}

	// 1. 연결 요소의 구성원과 크기를 알아낸다.
	int cnt = 1;
	vector<int> gs(cnt);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == -1) {
				int size = bfs(i, j, cnt++);
				gs.push_back(size);
				ans = max(ans, size + 1);
			}
		}
	}

	// 2. 두 개 이상의 연결 요소를 연결하는 위치를 저장한다.
	vector<pii> pos;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0 && good2(i, j)) {
				pos.push_back({ i,j });
			}
		}
	}
	
	// 3. 앞서 저장한 모든 위치에 대하여 연결한 그룹의 크기를 확인한다.
	for (int i = 0; i < pos.size(); i++) {
		int x, y;
		tie(x, y) = pos[i];
		vector<bool> check2(cnt);
		int sum = 0;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (good(nx, ny)) {
				int g = a[nx][ny];
				if (!check2[g]) {
					check2[g] = true;
					sum += gs[g];
				}
			}
		}
		ans = max(ans, sum + 1);
	}
	cout << ans;
}