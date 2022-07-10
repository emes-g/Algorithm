#include <iostream>
using namespace std;
int ans, t[15], p[15];

// 시간복잡도 : O(2^n)

void go(int day, int profit, int n) {
	if (day > n) {
		return;
	}
	else if (day != n) {
		go(day + t[day], profit + p[day], n);
		go(day + 1, profit, n);
	}
	ans = max(ans, profit);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> p[i];
	}
	go(0, 0, n);
	cout << ans;
	return 0;
}
