#include <iostream>
#include <vector>
using namespace std;
const int MAX = 4001;
bool a[MAX][MAX];
int degree[MAX];

// <문제 파악>
// 개선된 다중 for문
// 시간복잡도 : O(N^2 + NM)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x][y] = a[y][x] = true;
		degree[x]++;
		degree[y]++;
	}

	// 2. solve (brute force)
	int ans = 12e3;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[i][j]) {	// 최대 M번 해당 조건을 만족 가능
				for (int k = j + 1; k <= n; k++) {	// O(NM)
					if (a[i][k] && a[j][k]) {
						ans = min(ans, degree[i] + degree[j] + degree[k] - 6);
					}
				}
			}
		}
	}
	cout << (ans == 12e3 ? -1 : ans);
}