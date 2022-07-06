#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000000;
const int MOD = 1000000009;
long long dp[MAX + 1];

// dp[n] : 자연수 n을 1, 2, 3의 합으로 나타내는 방법의 수

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= MAX; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
	}

	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}