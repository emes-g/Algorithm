#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef pair<int, int> pii;
const int MAX = 10000;
int h, w;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

// <문제 파악>
// 특정 지점에서 죄수들과 상근이가 만나 함께 탈옥하는 BFS 문제
// 시간 복잡도 : O(NM)

// <해설>
// 두 죄수를 A,B 그리고 CASE(N)을 죄수 N이 탈출하기 위해 연 문의 개수라고 하자.
// 이때 해당 문제의 답은 CASE(A) + CASE(B) - CASE(A,B)이다.
// CASE(A)와 CASE(B)는 각자 BFS를 돌리면 O(NM)만에 파악할 수 있지만 CASE(A,B)는 그렇지 못하다.
// 여기서 생각해볼 수 있는 것이 바로 상근이의 존재이다.
// 상근이가 감옥 바깥에 존재한다고 했으므로 해당 문제는 세 사람이 특정 지점에서 탈출하는 문제가 된다.
// 즉 각 사람이 특정 지점까지 가기 위해 연 문의 최소 개수를 따로 저장해 두고,
// 이를 모든 지점에 대하여 처리해주면 된다는 뜻이다.

vector<vector<int>> bfs(vector<string>& a, int x, int y) {
	vector<vector<int>> dist(h, vector<int>(w, MAX));
	queue<pii> q;
	q.push({ x,y });
	dist[x][y] = 0;
	while (!q.empty()) {
		tie(x, y) = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
				if (a[nx][ny] == '#') {
					if (dist[nx][ny] > dist[x][y] + 1) {
						dist[nx][ny] = dist[x][y] + 1;
						q.push({ nx,ny });
					}
				}
				else if (a[nx][ny] != '*') {
					if (dist[nx][ny] > dist[x][y]) {
						dist[nx][ny] = dist[x][y];
						q.push({ nx,ny });
					}
				}
			}
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		// 1. input
		cin >> h >> w;
		vector<string> a(h + 2);
		for (int i = 1; i <= h; i++) {
			cin >> a[i];
			a[i] = '.' + a[i] + '.';
		}
		h += 2;
		w += 2;
		for (int i = 0; i < w; i++) {
			a[0] += '.';
			a[h - 1] += '.';
		}
		int x1, y1, x2, y2;
		x1 = y1 = x2 = y2 = -1;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (a[i][j] == '$') {
					if (x1 == -1) {
						x1 = i;
						y1 = j;
					}
					else {
						x2 = i;
						y2 = j;
					}
				}
			}
		}

		// 2. solve (bfs)
		vector<vector<int>> d1, d2, d3;
		d1 = bfs(a, x1, y1);
		d2 = bfs(a, x2, y2);
		d3 = bfs(a, 0, 0);
		int ans = MAX;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (a[i][j] != '*') {
					if (a[i][j] == '#') {
						ans = min(ans, d1[i][j] + d2[i][j] + d3[i][j] - 2);
					}
					else {
						ans = min(ans, d1[i][j] + d2[i][j] + d3[i][j]);
					}
				}
			}
		}
		cout << ans << '\n';
	}
}