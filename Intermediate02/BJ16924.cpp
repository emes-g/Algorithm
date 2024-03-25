#include <iostream>
using namespace std;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, m, ans;
int a[100][100];

// <문제 파악>
// 중심부를 찾아 십자가를 완성한다.
// 시간 복잡도 : O(n * m)

// <배열 a 값>
// -2		십자가의 구성 원소인 *이다.
// -1		십자가의 구성 원소가 아닌 *이다.
// 0		빈 칸이다.
// 자연수	십자가의 중심이며 값으로는 십자가의 크기가 저장되어 있다.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			if (str[j] == '*') {
				a[i][j] = -1;
			}
		}
	}

	// 1. 중심부 찾기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j]) {
				int depth = 100;
				for (int k = 0; k < 4; k++) {
					int nx = i;
					int ny = j;
					int temp = 0;
					while (true) {
						nx += dx[k];
						ny += dy[k];
						if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
							if (a[nx][ny]) {
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
				a[i][j] = (depth ? depth : -1);
			}
		}
	}

	// 2. 십자가 만들기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int depth = a[i][j];
			if (depth > 0) {
				for (int k = 0; k < 4; k++) {
					int nx = i;
					int ny = j;
					int temp = depth;
					while (temp--) {
						nx += dx[k];
						ny += dy[k];
						if (a[nx][ny] < 0) {	// 십자가의 중심은 건드리지 않는다.
							a[nx][ny] = -2;
						}
					}
				}
			}
		}
	}

	// 3. 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == -1) {	// 십자가의 구성 원소가 아닌 *이 존재한다면
				cout << -1;
				return 0;
			}
			else if (a[i][j] > 0) {
				ans++;
			}
		}
	}
	cout << ans << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] > 0) {
				cout << i + 1 << ' ' << j + 1 << ' ' << a[i][j] << '\n';
			}
		}
	}
}