#include <iostream>
#include <vector>
using namespace std;
vector<int> a;
int n, l, r, x, ans;

void go(int level, int index, int easy, int hard, int sum, bool prev) {
	if (level >= 2 && prev) {
		if (sum >= l && hard - easy >= x) {
			ans++;
		}
	}
	if (index >= n) {
		return;
	}
	if (sum + a[index] <= r) {
		go(level + 1, index + 1, min(easy, a[index]), max(hard, a[index]), sum + a[index], true);
	}
	go(level, index + 1, easy, hard, sum, false);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	cin >> n >> l >> r >> x;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// 2. solve (brute force)
	go(0, 0, 1e6, 0, 0, false);
	cout << ans;
}