#include <iostream>
#include <vector>
using namespace std;
const int MOD = 9901;

// dp[k][n] : 2*n 배열에 사자를 배치하는 경우의 수
// 단, 정수 k에 대응하여 n열의 사자 배치가 정해진다.
// k : 0 -> 위에 사자 배치
// k : 1 -> 아래에 사자 배치
// k : 2 -> 사자 배치 X

int main() {
	int n, ans = 0;
	cin >> n;
	vector<vector<int>> dp(3, vector<int>(n));	// int dp[3][n]
	
	for (int i = 0; i < 3; i++) {
		dp[i][0] = 1;
	}
	for (size_t i = 1; i < n; i++) {
		dp[0][i] = (dp[1][i - 1] + dp[2][i - 1]) % MOD;
		dp[1][i] = (dp[0][i - 1] + dp[2][i - 1]) % MOD;
		dp[2][i] = (dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1]) % MOD;
	}

	for (int i = 0; i < 3; i++) {
		ans += dp[i][n - 1];
		ans %= MOD;
	}
	cout << ans;
	return 0;
} 
