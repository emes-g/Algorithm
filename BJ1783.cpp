#include <iostream>
using namespace std;

int main() {
	int n, m, ans = 0;
	cin >> n >> m;
	if (n == 1 || m == 1) {	// 이동 불가
		cout << 1;
		return 0;
	}
	else if (n == 2) {	// 가로 2칸씩 이동
		if (m >= 7) {
			cout << 4;
		}
		else if (m >= 5) {
			cout << 3;
		}
		else if (m >= 3) {
			cout << 2;
		}
		else {
			cout << 1;
		}
		return 0;
	}

	if (m >= 7) {	// 가로 1칸씩 이동 가능
		ans += 2;
		m -= 4;
		ans += m;
		cout << ans;
	}
	else if (m >= 4) {
		cout << 4;
	}
	else if (m == 3) {
		cout << 3;
	}
	else {
		cout << 2;
	}
}