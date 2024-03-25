#include <iostream>
#include <algorithm>
using namespace std;
int a[8];

// 시간복잡도 : O(N * N!)

int main() {
	// 1. input
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// 2. solve
	sort(a, a + n);
	do {
		int sum = 0;
		for (int i = 0; i < n - 1; i++) {
			sum += abs(a[i] - a[i + 1]);
		}
		ans = max(ans, sum);
	} while (next_permutation(a, a + n));

	// 3. output
	cout << ans;
	return 0;
}