#include <iostream>
using namespace std;

bool is_prime(int x) {
	if (x < 2) {
		return false;
	}
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int t, cnt = 0;
	cin >> t;
	while (t--) {
		int num;
		cin >> num;
		if (is_prime(num)) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}