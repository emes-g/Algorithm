#include <iostream>
using namespace std;
int cnt, a[12], num[6];

// 시간복잡도 : O(T * 3^N)

void go(int sum, int goal) {
	if (sum > goal) {
		return;
	}
	else if (sum == goal) {
		cnt++;
		return;
	}
	go(sum + 1, goal);
	go(sum + 2, goal);
	go(sum + 3, goal);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		go(0, n);
		cout << cnt << '\n';
		cnt = 0;
	}
	return 0;
}