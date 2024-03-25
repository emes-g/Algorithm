#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000000;

// dp[n][k] : 구간 [0~n]에 있는 정수 k개를 더하여 그 합이 n이 되는 경우의 수

int main() {
	int n, k;
	cin >> n >> k;
	vector<vector<int>> dp(n + 1, vector<int>(k + 1));
	fill_n(dp[0].begin() + 1, k, 1);
	for (int i = 0; i <= n; i++) {
		dp[i][1] = 1;
	}

	for (size_t i = 1; i <= n; i++) {
		for (size_t j = 2; j <= k; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
		}
	}

	cout << dp[n][k];
	return 0;
}