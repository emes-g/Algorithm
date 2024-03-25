#include <iostream>
using namespace std;
int a[20];

int main() {
	int n, s, ans = 0;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int full = (1 << n) - 1;
	for (int i = full; i > 0; i = (i - 1) & full) {	// 모든 부분집합 순회
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {	// 해당 비트가 켜져 있다면
				sum += a[j];
			}
		}
		if (sum == s) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}