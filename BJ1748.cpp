#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
	int sum[9] = { 0 };
	for (int i = 1; i < 9; i++) {
		sum[i] = sum[i - 1] + 9 * pow(10, i - 1) * i;
	}

	int n, size, ans = 0;
	cin >> n;
	size = to_string(n).size();

	ans = sum[size - 1] + (n - pow(10, size - 1) + 1) * size;
	cout << ans;
	return 0;
}