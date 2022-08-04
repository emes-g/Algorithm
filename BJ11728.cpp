#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	// 2. solve (merge)
	vector<int> ans(n + m);
	int i = 0, j = 0, k = 0;
	while (i < n && j < m) {
		if (a[i] <= b[j]) {
			ans[k++] = a[i++];
		}
		else {
			ans[k++] = b[j++];
		}
	}
	while (i < n) {
		ans[k++] = a[i++];
	}
	while (j < m) {
		ans[k++] = b[j++];
	}

	// 3. output
	for (int i = 0; i < n + m; i++) {
		cout << ans[i] << ' ';
	}
}
