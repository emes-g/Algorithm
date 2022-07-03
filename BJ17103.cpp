#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000;
vector<bool> check(MAX + 1, true);
vector<int> prime;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	for (int i = 2; i <= MAX; i++) {	// 기존 에라토스테네스의 체와 다른 범위
		if (check[i]) {
			prime.push_back(i);
			for (int j = i * 2; j <= MAX; j += i) {
				check[j] = false;
			}
		}
	}

	while (t--) {
		int n, cnt = 0;
		cin >> n;
		for (int i = 0; i < prime.size(); i++) {
			if (prime[i] <= n / 2) {
				if (check[n - prime[i]]) {
					cnt++;
				}
			}
			else {
				break;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
