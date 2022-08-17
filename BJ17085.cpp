#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int> t;
vector<vector<int>> a;
int n, m, ans;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

// <좋은 예제 모음>
// [1]
// 3 3
// .#.
// ###
// .#.
// ans : 1

// [2]
// 5 8
// ..#..#..
// ..#..#..
// ########
// ..#..#..
// ..#..#..
// ans : 25

bool good(int x, int y, int depth, vector<vector<int>>& temp) {
	if (temp[x][y] == 2) {
		return false;
	}
	for (int k = 0; k < 4; k++) {
		int nx = x;
		int ny = y;
		for (int s = 0; s < depth; s++) {
			nx += dx[k];
			ny += dy[k];
			if (temp[nx][ny] == 2) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	a.assign(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			if (str[j] == '#') {
				a[i][j] = 1;
			}
		}
	}

	// 1. 십자가의 중심 찾기
	vector<t> g;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1) {
				int depth = 15;
				for (int k = 0; k < 4; k++) {
					int nx = i;
					int ny = j;
					int temp = 0;
					while (true) {
						nx += dx[k];
						ny += dy[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
							if (a[nx][ny] == 1) {
								temp++;
							}
							else {
								break;
							}
						}
						else {
							break;
						}
					}
					depth = min(depth, temp);
				}
				while (depth >= 0) {	// 같은 위치에서 크기만 작은 십자가를 계속 추가 (∵ [2])
					g.push_back({ depth--,i,j });
				}
			}
		}
	}
	sort(g.begin(), g.end(), greater<t>());

	// 2. 곱 구하기
	for (int i = 0; i < g.size(); i++) {	// 십자가 1 선정
		int depth1, x1, y1, area1;
		tie(depth1, x1, y1) = g[i];
		area1 = 4 * depth1 + 1;
		for (int j = i + 1; j < g.size(); j++) {	// 십자가 2 선정
			int depth2, x2, y2, area2;
			tie(depth2, x2, y2) = g[j];
			area2 = 4 * depth2 + 1;
			if (area1 * area2 <= ans) {
				break;
			}

			vector<vector<int>> temp(a);	// 십자가 1 그리기
			temp[x1][y1] = 2;
			for (int k = 0; k < 4; k++) {
				int nx = x1;
				int ny = y1;
				for (int s = 0; s < depth1; s++) {
					nx += dx[k];
					ny += dy[k];
					temp[nx][ny] = 2;
				}
			}
			
			if (good(x2, y2, depth2, temp)) {	// 십자가 2 그리기
				ans = max(ans, area1 * area2);
			}
		}
	}
	cout << ans;
}