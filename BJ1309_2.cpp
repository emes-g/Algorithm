#include <iostream>
#include <vector>
using namespace std;
const int MOD = 9901;

// dp[n] : 2*n 배열에 사자를 배치하는 경우의 수

// dp[n] = dp[n-1](1) + dp[n-1](2) + dp[n-2](3)
// (1) : n열에 사자를 배치하지 않는 경우
// (2) : n열에 사자를 배치하는데, (n-1)열에 존재하는 사자와 이웃하지 않도록 배치
// (3) : n열에 사자를 배치하는데, (n-1)열에 사자가 존재하지 않았어서, (2)에서 고려하지 못했던 경우들

int main() {
	int n;
	cin >> n;
	vector<int> dp(n + 1);

	dp[0] = 1;
	dp[1] = 3;
	for (size_t i = 2; i <= n; i++) {
		dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % MOD;
	}

	cout << dp[n];
	return 0;
}
