#include <iostream>
#include <vector>
using namespace std;

// dp[n] : 정수 n을 만들기 위해 사용하는 연산의 최소 횟수

int main() {
	int n;
	cin >> n;
	vector<int> dp(n + 1, 0);
	for (size_t i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
	}
	cout << dp[n];
	return 0;
}
