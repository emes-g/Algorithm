#include <iostream>
#include <vector>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	vector<bool> check(n + 1, true);
	check[1] = false;
	
	for (int i = 2; i * i <= n; i++) {
		if (check[i]) {
			for (int j = i * i; j <= n; j += i) {
				check[j] = false;
			}
		}
	}

	for (int i = m; i <= n; i++) {
		if (check[i]) {
			cout << i << '\n';
		}
	}
	return 0;
}