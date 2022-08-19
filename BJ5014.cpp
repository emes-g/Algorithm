#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
const int MAX = 1000001;
vector<bool> check;
int f, s, g, u, d;

// <문제 파악>
// s층에서 g층까지 가기 위해 눌러야 하는 버튼의 최소 횟수
// → 버튼의 가중치가 1인 상황에서 최소 횟수를 구하는 것이므로 BFS를 활용한다.

// 시간복잡도 : O(F)
// (∵ 모든 층을 방문하는 경우)

bool bfs() {
	int dx[2] = { u,-d };
	queue<pair<int, int>> q;
	q.push({ s,0 });
	check[s] = true;
	while (!q.empty()) {
		int x, cnt;
		tie(x, cnt) = q.front();
		q.pop();
		if (x == g) {
			cout << cnt;
			return true;
		}
		for (int k = 0; k < 2; k++) {
			int nx = x + dx[k];
			if ((1 <= nx && nx <= f) && !check[nx]) {
				q.push({ nx,cnt + 1 });
				check[nx] = true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> f >> s >> g >> u >> d;
	check.resize(f + 1);
	if (!bfs()) {
		cout << "use the stairs";
	}
}