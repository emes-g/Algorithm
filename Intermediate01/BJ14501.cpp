#include <iostream>
using namespace std;
int n, ans, t[15], p[15];

void go(int day, int sum) {
	if (day > n) {
		return;
	}
	else if(day == n) {
		ans = max(ans, sum);
		return;
	}
	go(day + t[day], sum + p[day]);
	go(day + 1, sum);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> p[i];
	}
	go(0, 0);
	cout << ans;
}