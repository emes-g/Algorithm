#include <iostream>
#include <cmath>
using namespace std;
int k;

// 갤러리 참고

void go(int n, int x, int y) {
	if (n == 1) {
		cout << x << ' ' << y << '\n';
		return;
	}
	go(n - 1, x, 6 - x - y);
	cout << x << ' ' << y << '\n';
	go(n - 1, 6 - x - y, y);
}

int main() {
	cin >> k;
	int cnt = pow(2, k) - 1;
	cout << cnt << '\n';
	go(k, 1, 3);
}