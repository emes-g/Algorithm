#include <iostream>
using namespace std;
const int MAX = 4000001;
bool check[MAX];
int n, a[MAX];

void eratos() {
	for (int i = 2; i * i <= n; i++) {
		for (int j = i * i; j <= n; j += i) {
			check[j] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	cin >> n;

	// 2. solve (eratos & two pointer)
	eratos();
	int idx = 0;
	for (int i = 2; i <= n; i++) {
		if (!check[i]) {
			a[idx++] = i;
		}
	}

	int i = 0, j = 0, sum = 0, ans = 0;
	while (i <= j && j < idx) {
		if (sum < n) {
			sum += a[j++];
		}
		else if (sum == n) {
			ans++;
			sum += a[j++];
		}
		else {
			sum -= a[i++];
		}
	}
	while (sum >= n) {
		if (sum == n) {
			ans++;
		}
		sum -= a[i++];
	}
	cout << ans;
}