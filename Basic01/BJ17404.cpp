#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000000;

// dp[k][n] : n번째 집을 정수 k에 대응하는 색으로 칠했을 때의 최소 cost
// k : 0 -> red
// k : 1 -> green
// k : 2 -> blue

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n, ans = MAX;
	cin >> n;
	vector<vector<int>> a(3, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		cin >> a[0][i] >> a[1][i] >> a[2][i];
	}

	// 2. solve (dp)
	for (int i = 0; i < 3; i++) {
		vector<vector<int>> dp(3, vector<int>(n + 1, MAX));
		dp[i][1] = a[i][1];
		for (size_t j = 2; j <= n; j++) {
			dp[0][j] = min(dp[1][j - 1], dp[2][j - 1]) + a[0][j];
			dp[1][j] = min(dp[0][j - 1], dp[2][j - 1]) + a[1][j];
			dp[2][j] = min(dp[0][j - 1], dp[1][j - 1]) + a[2][j];
		}
		dp[i][n] = MAX;

		for (int j = 0; j < 3; j++) {
			if (ans > dp[j][n]) {
				ans = dp[j][n];
			}
		}
	}

	// 3. output
	cout << ans;
	return 0;
}