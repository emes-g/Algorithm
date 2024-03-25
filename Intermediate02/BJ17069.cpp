#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int dx[3] = { 0,1,1 };
int dy[3] = { 1,0,1 };
ll dp[32][32][3];
bool a[32][32];
int n;

// <문제 파악>
// optimal substructure & overlapping subproblem
// → DP 문제임을 확인
// dp[x][y][dir] : 파이프의 끝부분이 dir방향으로 (x,y)에 위치할 수 있는 방법의 수

bool good(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < n && !a[x][y];
}

bool good2(int x, int y) {
	return good(x, y) && good(x - 1, y) && good(x, y - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// 1. input
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	// 2. solve (dp)
	dp[0][1][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 2; j < n; j++) {
			if (good(i, j)) {
				dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
				if (i == 0) {
					continue;
				}
				dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];
			}
			if (good2(i, j)) {
				dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
			}
		}
	}

	// 3. output
	ll ans = 0;
	for (int i = 0; i < 3; i++) {
		ans += dp[n - 1][n - 1][i];
	}
	cout << ans;
}