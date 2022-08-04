#include <iostream>
#include <cmath>
using namespace std;

// <분할 정복>
// 큰 하나의 경우를 해결하면,
// 작은 하나의 경우도 그 방법대로 해결할 수 있다!

// <문제 파악>
// 현재 탑의 맨 밑에 있는 원판을 목적 장대로 옮겨야 한다!
// 1. (n-1)개의 원판을 현재 장대에서 빈 장대로 옮긴다.
// 2. 현재 장대에 있는 남은 1개의 원판을 (1)에서 사용하지 않은 장대(목적 장대)로 옮긴다.
// 3. 빈 장대로 옮겨졌던 (n-1)개의 원판을 목적 장대로 옮긴다.

void go(int n, int x, int y) {
	if (n == 1) {
		cout << x << ' ' << y << '\n';
		return;
	}
	// 아래 코드에서 inorder 느낌이 난다.
	go(n - 1, x, 6 - x - y);
	cout << x << ' ' << y << '\n';
	go(n - 1, 6 - x - y, y);
}

int main() {
	int k;
	cin >> k;
	int cnt = pow(2, k) - 1;
	cout << cnt << '\n';
	go(k, 1, 3);
}
