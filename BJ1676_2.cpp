#include <iostream>
using namespace std;

int solve(int n, int num) {
	int div = num, cnt = 0;
	while (n / div != 0) {
		cnt += n / div;
		div *= num;
	}
	return cnt;
}

int main() {
	int n;
	cin >> n;
	cout << solve(n, 5);
	return 0;
}