#include <iostream>
#include <vector>
using namespace std;

// dp[k][n] : n번째 집을 정수 k에 대응하는 색으로 칠했을 때의 최소 cost
// k : 0 -> red
// k : 1 -> green
// k : 2 -> blue

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, ans = 1000000;
	cin >> n;
	vector<vector<int>> paint(3, vector<int>(n + 1)), dp(3, vector<int>(n + 1));
	for (int i = 1; i <= n; i++) {
		cin >> paint[0][i] >> paint[1][i] >> paint[2][i];
	}

	dp[0][1] = paint[0][1];
	dp[1][1] = paint[1][1];
	dp[2][1] = paint[2][1];
	for (size_t i = 2; i <= n; i++) {
		dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + paint[0][i];
		dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + paint[1][i];
		dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + paint[2][i];
	}

	for (int i = 0; i < 3; i++) {
		if (ans > dp[i][n]) {
			ans = dp[i][n];
		}
	}
	cout << ans;
	return 0;
}