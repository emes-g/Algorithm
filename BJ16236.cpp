#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#include <algorithm>
using namespace std;
int n, a[20][20], dist[20][20];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

// <핵심>
// 1. 먹을 수 있는 고기 후보들을 정해 준 다음, 거리와 위치를 비교하여 먹는다.
// (위 과정은 sort 한 번으로 해결된다)

// 2. 상어가 고기를 하나 먹을 때마다 처리해야 하는 과정이 존재한다.
//  (1) 상어가 이동했으므로, 현재 위치에서 물고기들과의 거리를 다시 재야 한다.
//   → dist 초기화
//  (2) 물고기를 먹었으므로 해당 위치의 a값을 0으로 바꿔주어야 한다.
//   → a[x][y] = 0

int bfs(int x, int y) {
	int exp = 0, w = 2, ans = 0;
	while (true) {
		memset(dist, -1, sizeof(dist));
		queue<pair<int, int>> q;
		vector<tuple<int, int, int>> fish;
		q.push({ x,y });
		a[x][y] = dist[x][y] = 0;
		while (!q.empty()) {
			x = q.front().first;
			y = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
					if (a[nx][ny] > w) {	// 벽 (못 먹는 물고기들)
						continue;
					}
					else if (dist[nx][ny] == -1) {	
						// 적어도 이동은 가능한 공간 (고기는 못 먹을 수도 있는 공간)
						dist[nx][ny] = dist[x][y] + 1;
						q.push({ nx,ny });
						if (a[nx][ny] > 0 && a[nx][ny] < w) {	// 고기를 먹을 수 있는 상황이라면 먹어준다.
							fish.push_back({ dist[nx][ny],nx,ny });
						}
					}
				}
			}
		}
		if (fish.size() == 0) {	// 엄마 상어를 부르러 간 경우 (더 이상 먹을 수 있는 고기가 없다)
			return ans;
		}
		// 먹을 수 있는 고기 후보들 중 골라 먹기
		sort(fish.begin(), fish.end());	// 오름차순
		int dist2, x2, y2;
		tie(dist2, x2, y2) = fish[0];
		ans += dist2;
		x = x2;
		y = y2;
		if (++exp == w) {	// level up (아기 상어의 크기가 커진 경우)
			exp = 0;
			w++;
		}
	}
}

int main() {
	int x, y;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 9) {
				x = i;
				y = j;
			}
		}
	}
	cout << bfs(x, y);
}