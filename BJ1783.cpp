#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	if (n == 1) {	// 이동 불가
		cout << 1;
	}
	else if (n == 2) {
		// 본인이 있는 열 제외, (m-1)열 중에서 2열 단위로 움직일 수 있다.
		cout << min(4, (m - 1) / 2 + 1);
	}
	else {
		if (m >= 7) {
			cout << m - 2;
		}
		else {
			cout << min(4, m);
		}
	}
}
