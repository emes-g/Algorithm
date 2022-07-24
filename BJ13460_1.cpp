#include <iostream>
#include <vector>
using namespace std;
char a[10][10];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int ans = 11;

// <삼성 SW 역량 테스트 기출 문제>
// 최적의 알고리즘이라고 할 수는 없지만,
// 답 안 보고 혼자서 원트에 구현해낸 게 만족스럽다.
// 시간 복잡도 : O(4^10 + α)
// 2020kb/72ms

// <수정 사항>
// 이전에 상하 이동했으면 이번에는 좌우 이동만,
// 이전에 좌우 이동했으면 이번에는 상하 이동만 하면 된다.
// 시간 복잡도 : O(4 * 2^9 + α)
// 2020kb/0ms

void go(int level, int x1, int y1, int x2, int y2, int prev) {
	if (level == 11) {	// 10번 초과 (실패)
		return;
	}
	else if (a[x2][y2] == 'O') {	// 파란 구슬이 빠진 경우 (실패)
		return;
	}
	else if (a[x1][y1] == 'O') {	// 빨간 구슬만 빠진 경우 (성공)
		ans = min(ans, level);
		return;
	}
	int start = 0, end = 4;
	if (level != 0) {	// 이전 이동 방향에 따라 현재 이동 방향 결정
		if (prev < 2) {
			start = 2;
			end = 4;
		}
		else {
			start = 0;
			end = 2;
		}
	}
	for (int i = start; i < end; i++) {
		int nx1 = x1;
		int ny1 = y1;
		while (a[nx1 + dx[i]][ny1 + dy[i]] != '#') {	// 빨간 구슬 이동
			nx1 += dx[i];
			ny1 += dy[i];
			if (a[nx1][ny1] == 'O') {
				break;
			}
		}
		int nx2 = x2;
		int ny2 = y2;
		while (a[nx2 + dx[i]][ny2 + dy[i]] != '#') {	// 파란 구슬 이동
			nx2 += dx[i];
			ny2 += dy[i];
			if (a[nx2][ny2] == 'O') {
				break;
			}
		}
		if (nx1 == nx2 && ny1 == ny2 && a[nx1][ny1] != 'O') {	// 구슬 위치가 겹친 경우
			if (i == 0) {	// up
				if (x1 < x2) {
					nx2++;
				}
				else {
					nx1++;
				}
			}
			else if (i == 1) {	// down
				if (x1 < x2) {
					nx1--;
				}
				else {
					nx2--;
				}
			}
			else if (i == 2) {	// left
				if (y1 < y2) {
					ny2++;
				}
				else {
					ny1++;
				}
			}
			else {	// right
				if (y1 < y2) {
					ny1--;
				}
				else {
					ny2--;
				}
			}
		}
		go(level + 1, nx1, ny1, nx2, ny2, i);
	}
}

int main() {
	// 1. input
	int n, m;
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'R') {
				x1 = i;
				y1 = j;
				a[i][j] = '.';
			}
			else if (a[i][j] == 'B') {
				x2 = i;
				y2 = j;
				a[i][j] = '.';
			}
		}
	}

	// 2. solve (brute force)
	go(0, x1, y1, x2, y2, 0);
	cout << (ans == 11 ? -1 : ans);
}
