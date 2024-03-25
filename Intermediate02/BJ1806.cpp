#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n, s, a[100000];
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// 2. solve (two pointer)
	int l = 0, r = 0, sum = 0, ans = 1e5;
	while (l <= r && r < n) {
		if (sum < s) {
			sum += a[r++];
		}
		else if (sum == s) {
			ans = min(ans, r - l);
			sum += a[r++];
		}
		else {
			ans = min(ans, r - l);
			sum -= a[l++];
		}
	}
	while (sum >= s) {
		ans = min(ans, r - l);
		sum -= a[l++];
	}
	cout << (ans == 1e5 ? 0 : ans);
}