#include <iostream>
#include <vector>
using namespace std;
const int MOD = 10007;

// dp[n][i] : 길이가 n이고 첫 번째 자리가 i인 오르막 수의 개수
// 쉬운 계단 수 (10844) 문제를 풀고 오면 더 쉽다.

int main() {
	int n, ans = 0;
	cin >> n;
	vector<vector<int>> dp(n + 1, vector<int>(10));	// int dp[n+1][10]
	fill_n(dp[1].begin(), 10, 1);

	for (size_t i = 2; i <= n; i++) {
		dp[i][9] = dp[i - 1][9];
		for (int j = 8; j >= 0; j--) {	// size_t의 경우, 언더플로우가 발생
			dp[i][j] = (dp[i - 1][j] + dp[i][j + 1]) % MOD;
		}
	}

	for (size_t i = 0; i < 10; i++) {
		ans += dp[n][i];
		ans %= MOD;
	}
	cout << ans;
	return 0;
}