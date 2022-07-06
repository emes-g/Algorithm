#include <iostream>
#include <vector>
using namespace std;

// dp[n] : n번째 잔을 마신다고 할 때, 마실 수 있는 최대 포도주 양
// 하지만 시간을 꽤 써버려서 다른 방법을 찾고자 한다. (48ms)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, ans = 0;
	cin >> n;
	vector<int> arr(n + 1), dp(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1] = arr[1];
	if (n != 1) {
		dp[2] = arr[1] + arr[2];
	}
	for (int i = 3; i <= n; i++) {
		int temp = 0;
		for (int j = i - 3; j >= 0; j--) {
			if (temp < dp[j]) {
				temp = dp[j];
			}
		}

		dp[i] = max(dp[i - 2], temp + arr[i - 1]) + arr[i];
	}

	for (int i = 1; i <= n; i++) {
		if (ans < dp[i]) {
			ans = dp[i];
		}
	}
	cout << ans;
	return 0;
}