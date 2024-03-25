#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n;
	cin >> n;
	
	// 2. solve
	vector<int> c(n + 1);
	c[0] = 1;
	for (int i = 1; i <= n; i++) {
		c[i] = 0;
		for (int j = 0; j <= i - 1; j++) {
			c[i] += c[j] * c[i - 1 - j];
		}
	}
	cout << c[n];
}