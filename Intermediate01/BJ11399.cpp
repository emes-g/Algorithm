#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a, sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n;
	cin >> n;
	a.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// 2. solve (greedy)
	sort(a.begin(), a.end());
	sum.assign(n, 0);
	for (int i = 0; i < n; i++) {
		sum[i] = a[i];
		if (i != 0) {
			sum[i] += sum[i - 1];
		}
	}

	// 3. output
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += sum[i];
	}
	cout << ans;
}