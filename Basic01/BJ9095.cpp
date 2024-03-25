#include <iostream>
using namespace std;
int dp[11];

// dp[n] : 자연수 n을 1, 2, 3의 합으로 나타내는 방법의 수

void init() {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 10; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
}

int main() {
	init();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}