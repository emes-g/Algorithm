#include <iostream>
#include <vector>
using namespace std;

// dp[n][i] : 첫 번째 자리가 i인 n자리 이친수의 개수
// 단, 0으로 시작하는 수는 이친수가 아니므로 답을 출력할 때는 사용하지 않는다.

int main() {
	int n;
	cin >> n;
	vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));	// int dp[n+1][2]
	fill_n(dp[1].begin(), 2, 1);
	for (size_t i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	cout << dp[n][1];
	return 0;
}