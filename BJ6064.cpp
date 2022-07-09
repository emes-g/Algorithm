#include <iostream>
using namespace std;

// <유사 문제>
// 날짜 계산 (1476)

// <주의 사항>
// 나머지가 0일 때 예외 처리가 필요하다.

int main() {
	int t;
	cin >> t;
	while (t--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		for (int i = x; i <= m * n; i += m) {
			int mod = (i % n == 0) ? n : i % n;
			if (mod == y) {
				cout << i << '\n';
				break;
			}
			else if (i + m > m * n) {
				cout << -1 << '\n';
			}
		}
	}
	return 0;
}