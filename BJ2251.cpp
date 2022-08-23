#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> t;
const int MAX = 201;
bool check[MAX][MAX], ans[MAX];
int vol[3];
int from[6] = { 0,0,1,1,2,2 };	// dx, dy
int to[6] = { 1,2,0,2,0,1 };

// <문제 파악>
// 한 번 방문한 상태는 방문하지 않는 BFS(DFS) 문제
// 기존 그래프에서 상하좌우로 처리하던 이동과는 다른 유형이지만
// 본질은 같음

// 시간복잡도 : O(MAX^2)

void bfs() {
	queue<t> q;
	q.push({ 0,0,vol[2] });
	check[0][0] = true;
	ans[vol[2]] = true;
	while (!q.empty()) {
		int cur[3];	// x, y
		tie(cur[0], cur[1], cur[2]) = q.front();
		q.pop();
		for (int k = 0; k < 6; k++) {
			int next[3] = { cur[0], cur[1], cur[2] };	// nx, ny
			next[to[k]] += next[from[k]];
			next[from[k]] = 0;
			if (next[to[k]] >= vol[to[k]]) {
				next[from[k]] = next[to[k]] - vol[to[k]];
				next[to[k]] = vol[to[k]];
			}
			if (!check[next[0]][next[1]]) {	// 한 번도 방문하지 않은 상태라면
				check[next[0]][next[1]] = true;
				q.push({ next[0], next[1], next[2] });
				if (next[0] == 0) {
					ans[next[2]] = true;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	for (int i = 0; i < 3; i++) {
		cin >> vol[i];
	}
	
	// 2. bfs
	bfs();

	// 3. output
	for (int i = 0; i <= vol[2]; i++) {
		if (ans[i]) {
			cout << i << '\n';
		}
	}
}