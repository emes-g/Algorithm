#include <iostream>
#include <vector>
using namespace std;

// dp[n] : n을 제곱수들의 합으로 표현할 때, 가능한 항의 최소개수

int main() {
	int n;
	cin >> n;
	vector<int> dp(n + 1);
	dp[0] = 0;
	dp[1] = 1;
	for (size_t i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		for (size_t j = 2; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	cout << dp[n];
	return 0;
}
