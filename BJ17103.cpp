#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000;
vector<bool> check(MAX + 1, true);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	for (int i = 2; i * i <= MAX; i++) {
		if (check[i]) {
			for (int j = i * i; j <= MAX; j += i) {
				check[j] = false;
			}
		}
	}

	while (t--) {
		int n, cnt = 0;
		cin >> n;
		for (size_t i = 2; i <= n / 2; i++) {
			if (check[i] && check[n - i]) {
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}