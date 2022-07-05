#include <iostream>
#include <vector>
using namespace std;

// dp[n] : n자리 이친수의 개수

int main() {
	int n;
	cin >> n;
	vector<long long> dp(n + 1, 0);
	dp[1] = dp[2] = 1;
	for (size_t i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n];
	return 0;
}