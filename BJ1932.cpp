#include <iostream>
using namespace std;
const int SIZE = 500;
int dp[SIZE + 1][SIZE + 1];

// dp[n][k] : n번째 줄에서 k번째 수가 가질 수 있는 합의 최대치

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> dp[i][j];
		}
	}

	for (int i = 2; i <= n; i++) {
		dp[i][1] += dp[i - 1][1];
		dp[i][i] += dp[i - 1][i - 1];
		for (int j = 2; j < i; j++) {
			dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (ans < dp[n][i]) {
			ans = dp[n][i];
		}
	}
	cout << ans;
	return 0;
}