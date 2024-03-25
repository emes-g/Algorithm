#include <iostream>
#include <vector>
using namespace std;

// left[n]  : a[n]을 포함하며, 왼쪽부터 세는 LIS의 길이
// right[n] : a[n]을 포함하며, 오른쪽부터 세는 LIS의 길이

// <주의할 점>
// right라고 해서 인덱스가 반전되는 것이 아님!

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// 1. input
	int n, ans = 0;
	cin >> n;
	vector<int> a(n + 1), left(n + 1, 1), right(n + 1, 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	// 2. solve (dp)
	for (int i = 2; i <= n; i++) {
		for (int j = i - 1; j >= 1; j--) {
			if (a[i] > a[j]) {
				left[i] = max(left[i], left[j] + 1);
			}
		}
	}
	for (int i = n - 1; i >= 1; i--) {
		for (int j = i + 1; j <= n; j++) {
			if (a[i] > a[j]) {
				right[i] = max(right[i], right[j] + 1);
			}
		}
	}
	
	// 3. output
	for (int i = 1; i <= n; i++) {
		if (ans < left[i] + right[i] - 1) {
			ans = left[i] + right[i] - 1;
		}
	}
	cout << ans;
	return 0;
}