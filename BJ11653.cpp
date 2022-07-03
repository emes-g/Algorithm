#include <iostream>
using namespace std;

// 왜 i*i<=n까지만 검사하면 되는지에 관하여 확실히 알고 싶다.
// 왜일까?

int main() {
	int n;
	cin >> n;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			cout << i << '\n';
			n /= i;
		}
	}
	if (n > 1) {
		cout << n;
	}
	return 0;
}
