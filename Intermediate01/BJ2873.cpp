#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1000;
int r, c, a[MAX][MAX];

// <문제 파악>
// 기쁨이 양수이므로,
// 가능한 한 많은 정점을 방문하는 것이 좋다.

// dfs, bfs : 모든 정점을 한 번씩 방문하는 것이지, 이 문제에서는 사용할 수 없다.
// backtracking : 골인하기 위해 모든 정점을 방문했는지 확인하기 힘들고, 했다고 하더라도 너무 오랜 시간이 걸린다.
// ∴ 해당 문제는 greedy algorithm으로 해결하는 것이 좋겠다.

// 행과 열 모두 짝수개일때는 모든 칸을 방문할 수 없다.
// 반드시 방문하지 못하는 칸이 하나 생긴다.
// 왜?
// 출발점에서 도착점까지의 경로는 흰→검→흰→검→...→흰이다.
// 체스판의 총 흰 칸의 개수와 검은 칸의 개수가 동일한데, 
// 흰색칸에서 시작하여 흰색칸에서 끝나므로,
// 방문하지 못하는 검은색 칸이 필연적으로 발생할 수밖에 없다.

void move(string& s, char ch, int cnt) {
	for (int i = 0; i < cnt; i++) {
		s += ch;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
		}
	}

	// 2. solve (greedy)
	string s = "";
	if (r % 2) {	// 행이 홀수개
		for (int i = 0; i < r; i++) {
			if (i % 2 == 0) {
				move(s, 'R', c - 1);
				if (i != r - 1) {
					move(s, 'D', 1);
				}
			}
			else {
				move(s, 'L', c - 1);
				move(s, 'D', 1);
			}
		}
	}
	else if (c % 2) {	// 열이 홀수개
		for (int i = 0; i < c; i++) {
			if (i % 2 == 0) {
				move(s, 'D', r - 1);
				if (i != c - 1) {
					move(s, 'R', 1);
				}
			}
			else {
				move(s, 'U', r - 1);
				move(s, 'R', 1);
			}
		}
	}
	else {	// 행도 짝수개, 열도 짝수개
		int x = 0, y = 1;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if ((i + j) % 2 == 1 && a[i][j] < a[x][y]) {	// 기쁨이 가장 작은 칸 찾기 (방문하지 않을 칸)
					x = i;
					y = j;
				}
			}
		}
		
		int x1 = 0, y1 = 0;
		int x2 = r - 1, y2 = c - 1;
		string s2 = "";
		while (x2 - x1 > 1) {	// 행렬을 2*c 형태로 만든다.
			if (x1 / 2 != x / 2) {
				move(s, 'R', c - 1);
				move(s, 'D', 1);
				move(s, 'L', c - 1);
				move(s, 'D', 1);
				x1 += 2;
			}
			if (x / 2 != x2 / 2) {
				move(s2, 'R', c - 1);
				move(s2, 'D', 1);
				move(s2, 'L', c - 1);
				move(s2, 'D', 1);
				x2 -= 2;
			}
		}
		while (y2 - y1 > 1) {	// 행렬을 2*2 형태로 만든다.
			if (y1 / 2 != y / 2) {
				move(s, 'D', 1);
				move(s, 'R', 1);
				move(s, 'U', 1);
				move(s, 'R', 1);
				y1 += 2;
			}
			if (y / 2 != y2 / 2) {
				move(s2, 'D', 1);
				move(s2, 'R', 1);
				move(s2, 'U', 1);
				move(s2, 'R', 1);
				y2 -= 2;
			}
		}
		if (y1 == y) {
			move(s, 'R', 1);
			move(s, 'D', 1);
		}
		else {
			move(s, 'D', 1);
			move(s, 'R', 1);
		}
		reverse(s2.begin(), s2.end());
		s += s2;
	}
	cout << s;
}