#include <iostream>
using namespace std;

int getCount(int n, int num) {
	long long div = num;
	int cnt = 0;
	while (n / div != 0) {
		cnt += n / div;
		div *= num;
	}
	return cnt;
}

int solve(int n, int m) {
	int two = getCount(n, 2) - getCount(m, 2) - getCount(n - m, 2);
	int five = getCount(n, 5) - getCount(m, 5) - getCount(n - m, 5);
	return two < five ? two : five;
}

int main() {
	int n, m;
	cin >> n >> m;
	cout << solve(n, m);
	return 0;
}