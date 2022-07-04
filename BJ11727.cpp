#include <iostream>
using namespace std;
const int MOD = 10007;

// dp[n] : 2*n 크기의 직사각형을 채우는 방법의 수를 10007로 나눈 나머지

int main() {
	int n;
	cin >> n;
	int dp[1001];
	dp[1] = 1;
	dp[2] = 3;
	for (size_t i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % MOD;
	}
	cout << dp[n];
	return 0;
}