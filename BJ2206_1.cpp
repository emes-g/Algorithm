#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 1000000;
bool a[1000][1000], check[1000][1000];
int n, m;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

// 12740KB/60MS
// 유사 : 연속합2 (13398)

void bfs(vector<vector<int>>& vec, int x, int y) {
	memset(check, false, sizeof(check));
	queue<pair<int, int>> q;
	q.push({ x,y });
	check[x][y] = true;
	vec[x][y] = 1;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (!a[nx][ny] && !check[nx][ny]) {
					check[nx][ny] = true;
					vec[nx][ny] = vec[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			if (str[j] - '0') {
				a[i][j] = true;
			}
		}
	}

	// 2. solve (bfs)
	vector<vector<int>> down(n, vector<int>(m, MAX)), up(n, vector<int>(m, MAX));
	bfs(down, 0, 0);
	bfs(up, n - 1, m - 1);
	int ans = MAX;
	for (int i = 0; i < n; i++) {	// 벽을 부수는 경우
		for (int j = 0; j < m; j++) {
			if (a[i][j]) {
				// 상 → 하우, 좌 → 하우
				for (int k = 0; k < 4; k += 2) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					for (int s = 1; s < 4; s += 2) {
						int nx2 = i + dx[s];
						int ny2 = j + dy[s];
						if ((nx >= 0 && nx < n && ny >= 0 && ny < m) &&
							(nx2 >= 0 && nx2 < n && ny2 >= 0 && ny2 < m)) {
							if (!a[nx][ny] && !a[nx2][ny2]) {
								ans = min(ans, down[nx][ny] + up[nx2][ny2] + 1);
							}
						}
					}
				}
			}
		}
	}
	ans = min(ans, down[n - 1][m - 1]);	// 벽을 안 부수는 경우

	// 3. output
	cout << (ans == MAX ? -1 : ans);
}
