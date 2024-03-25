#include <iostream>
#include <algorithm>
using namespace std;

// <분할 정복>
// 큰 하나의 경우를 해결하면,
// 작은 하나의 경우도 그 방법대로 해결할 수 있다!

// <알고리즘>
// 1. 비트마스크를 통해 사분면 조각 번호의 좌표를 구한다.
// 2. 둘째 줄에 주어진 두 숫자(x,y)만큼 좌표를 이동시킨다.
// 3. 이동된 좌표의 사분면 조각 번호를 비트마스크를 통해 구한다.
// (1을 반대로)

int main() {
	long long d, x, y;
	string str;
	cin >> d >> str >> x >> y;
	reverse(str.begin(), str.end());

	// 1. 사분면 조각 번호의 좌표 구하기
	long long x1 = 0, y1 = 0;
	for (int i = 0; i < d; i++) {
		switch (str[i]) {
		case '1':
			y1 += (1LL << i);
			break;
		case '3':
			x1 += (1LL << i);
			break;
		case '4':
			x1 += (1LL << i);
			y1 += (1LL << i);
			break;
		}
	}

	// 2. 좌표를 x, y만큼 이동
	x1 -= y;
	y1 += x;
	if (x1 < 0 || x1 >= (1LL << d) || y1 < 0 || y1 >= (1LL << d)) { // 범위 초과
		cout << -1;
		return 0;
	}

	// 3. 이동된 좌표를 다시 사분면 조각 번호로 변환
	string ans = "";
	for (int i = 0; i < d; i++) {
		if ((1LL << i) & x1) {
			if ((1LL << i) & y1) {
				ans += '4';
			}
			else {
				ans += '3';
			}
		}
		else {
			if ((1LL << i) & y1) {
				ans += '1';
			}
			else {
				ans += '2';
			}
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
}