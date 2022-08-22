#include <iostream>
using namespace std;
int n, m;
int a[1001][1001], dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	// 2. solve (dp)
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = a[i][j];
			dp[i][j] += max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
		}
	}
	cout << dp[n][m];
}