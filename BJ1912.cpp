#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, ans = -1000;
	cin >> n;
	vector<int> a(n), dp(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	dp[0] = a[0];
	for (size_t i = 1; i < n; i++) {
		if (dp[i - 1] < 0) {
			dp[i] = a[i];
		}
		else {
			dp[i] = dp[i - 1] + a[i];
		}
	}

	for (int i = 0; i < n; i++) {
		if (ans < dp[i]) {
			ans = dp[i];
		}
	}
	cout << ans;
	return 0;
}