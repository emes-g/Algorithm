#include <iostream>
#include <vector>
using namespace std;

// dp[n] : 민규가 카드 n개를 갖기 위해 지불해야 하는 금액의 최솟값

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> p(n + 1, 0), dp(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	for (size_t i = 1; i <= n; i++) {
		dp[i] = p[i];
		for (int j = 1; j < i; j++) {
			dp[i] = min(dp[i], dp[j] + p[i - j]);
		}
	}
	cout << dp[n];
	return 0;
}