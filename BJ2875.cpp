#include <iostream>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	while (k--) {
		if (n >= 2 * m) {
			n--;
		}
		else {
			m--;
		}
	}
	cout << min(n / 2, m);
}