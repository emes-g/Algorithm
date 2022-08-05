#include <iostream>
using namespace std;
int ans, r, c;

// <분할 정복>
// 큰 하나의 경우를 해결하면,
// 작은 하나의 경우도 그 방법대로 해결할 수 있다!

// <문제 핵심>
// (r,c)가 존재하지 않는 영역은 확인할 필요가 없다.

void go(int n, int x, int y) {
	if (x == r && y == c) {
		cout << ans;
		exit(0);
	}
	else if (r >= x && r < x + n && c >= y && c < y + n) {	// 현재 영역에 (r,c)가 존재한다면
		go(n / 2, x, y);
		go(n / 2, x, y + n / 2);
		go(n / 2, x + n / 2, y);
		go(n / 2, x + n / 2, y + n / 2);
	}
	else {
		ans += n * n;
	}
}

int main() {
	int n;
	cin >> n >> r >> c;
	go((1 << n), 0, 0);
}