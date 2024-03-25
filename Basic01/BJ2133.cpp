#include <iostream>
using namespace std;
int dp[31];

// dp[n] : 3*n 크기의 벽을 채우는 경우의 수

int main() {
	int n;
	cin >> n;
	
	dp[2] = 3;
	for (int i = 4; i <= n; i += 2) {
		dp[i] = dp[i - 2] * 3 + 2;
		for (int j = i - 4; j >= 2; j -= 2) {
			dp[i] += dp[j] * 2;
		}
	}

	cout << dp[n];
	return 0;
}