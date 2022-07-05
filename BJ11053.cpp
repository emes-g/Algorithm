#include <iostream>
#include <vector>
using namespace std;

// dp[n] : a[n]을 포함한 LIS의 길이

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, ans = 0;
	cin >> n;
	vector<int> a(n), dp(n, 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (a[i] > a[j]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
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