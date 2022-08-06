#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	
	// 2. output
	long long ans = a[0], ans_cnt = 1, cnt = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i - 1]) {
			if (cnt > ans_cnt) {
				ans_cnt = cnt;
				ans = a[i - 1];
			}
			cnt = 1;
		}
		else {
			cnt++;
		}
	}
	if (cnt > ans_cnt) {
		ans_cnt = cnt;
		ans = a[n - 1];
	}
	cout << ans;
}