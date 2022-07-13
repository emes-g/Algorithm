#include <iostream>
#include <vector>
using namespace std;
const int MAX = 5000;
int s[20][20], start[10], link[10];

int main() {
	// 1. input
	int n, ans = MAX;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}
	
	// 2. solve (bitmask)
	for (int i = 0; i < (1 << n); i++) {
		int size = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				size++;
			}
		}
		if (size == n / 2) {
			int s_idx = 0, l_idx = 0, s_total = 0, l_total = 0;
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) {
					start[s_idx++] = j;
				}
				else {
					link[l_idx++] = j;
				}
			}

			for (int j = 0; j < n / 2; j++) {
				for (int k = 0; k < n / 2; k++) {
					if (j != k) {
						s_total += s[start[j]][start[k]];
						l_total += s[link[j]][link[k]];
					}
				}
			}
			ans = min(ans, abs(s_total - l_total));
		}
	}
	
	// 3. output
	cout << ans;
	return 0;
}