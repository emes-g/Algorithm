#include <iostream>
using namespace std;
int a, b, c, x, y, ans;

// <문제 파악>
// 정확히 X,Y마리를 구매하는 것이 아니라 그 이상 구매해도 됨.
// → 즉, 예를 들어 양념치킨 1마리 값보다 반반치킨 2마리 값이 더 싸다면 반반치킨을 구매해야 함.

int main() {
	// 1. input
	cin >> a >> b >> c >> x >> y;

	// 2. solve
	int temp = min(x, y);
	x -= temp;
	y -= temp;
	ans += min(2 * c, a + b) * temp;
	if (x == 0) {
		ans += min(2 * c, b) * y;
	}
	else {
		ans += min(2 * c, a) * x;
	}
	cout << ans << '\n';
}