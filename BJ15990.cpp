#include <iostream>
using namespace std;
const int MAX = 100000;
const int MOD = 1000000009;
int dp[MAX + 1][4];

void init() {
	for (int i = 1; i < 4; i++) {
		fill_n(dp[i], 4, 0);
		dp[i][i] = 1;
	}
	dp[3][1] = dp[3][2] = 1;

	for (int i = 4; i <= MAX; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	init();

	int t;
	cin >> t;
	while (t--) {
		long long n, ans = 0;
		cin >> n;
		for (int i = 1; i <= 3; i++) {
			ans += dp[n][i];
			ans %= MOD;
		}
		cout << ans << '\n';
	}
	return 0;
}