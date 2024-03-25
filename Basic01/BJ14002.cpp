#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// dp[n] : a[n]을 포함한 LIS의 길이

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, len = 0;
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
		if (len < dp[i]) {
			len = dp[i];
		}
	}
	cout << len << '\n';

	stack<int> s;
	for (int i = n - 1; i >= 0; i--) {
		if (len == dp[i]) {
			s.push(a[i]);
			len--;
		}
	}
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
}