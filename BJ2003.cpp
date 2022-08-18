#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n, m, a[10000];
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// 2. solve (two pointer)
	int l = 0, r = 0, sum = 0, ans = 0;
	while (l <= r && r < n) {
		if (sum < m) {
			sum += a[r++];
		}
		else if (sum == m) {
			sum += a[r++];
			ans++;
		}
		else {
			sum -= a[l++];
		}
	}
	while (sum >= m) {
		if (sum == m) {
			ans++;
		}
		sum -= a[l++];
	}
	cout << ans;
}