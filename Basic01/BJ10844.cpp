#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000000;

// dp[n][i] : 길이가 n이고 첫 번째 자리가 i인 계단수의 개수
// 단, 0으로 시작하는 수는 계단수가 아니므로 답을 출력할 때 출력해서는 안 된다!

int main() {
	int n, ans = 0;
	cin >> n;
	vector<vector<int>> dp(n + 1, vector<int>(10, 0));	// int dp[n+1][10]
	fill_n(dp[1].begin(), 10, 1);
	for (size_t i = 2; i <= n; i++) {
		for (size_t j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
		}
		dp[i][0] = dp[i - 1][1];
		dp[i][9] = dp[i - 1][8];
	}

	for (int i = 1; i <= 9; i++) {
		ans += dp[n][i];
		ans %= MOD;
	}
	cout << ans;
	return 0;
}