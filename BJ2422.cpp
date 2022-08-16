#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MAX = 201;
bool a[MAX][MAX];

// 시간복잡도 : O(n^3)
// 유사 문제 : 세 친구 (17089)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n, m;
	cin >> n >> m;
	memset(a, true, sizeof(a));
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x][y] = a[y][x] = false;
	}

	// 2. solve (brute force)
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				if (a[i][j] && a[i][k] && a[j][k]) {
					ans++;
				}
			}
		}
	}
	cout << ans;
}
