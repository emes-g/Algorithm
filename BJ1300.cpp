#include <iostream>
using namespace std;
int n, k;

// <문제 파악>
// k번째 수가 무엇인지는 모르지만,
// 어떤 수가 k번째 수인지 아닌지는 알 수 있다.
// → '이분 탐색'을 이용한다.

// 결정 문제 : 앞서 언급한 어떤 수가 mid인가?

int calc(int x) {	// 수 x가 등장하는 첫 번째 위치 반환
	int pos = 0;
	x--;
	for (int i = 1; i <= n; i++) {
		pos += min(x / i, n);
	}
	return pos + 1;
}

int binary_search(int left, int right) {
	while (left <= right) {
		int mid = (left + right) / 2;
		int p1 = calc(mid);
		int p2 = calc(mid + 1);
		if (k < p1) {
			right = mid - 1;
		}
		else if (k >= p2) {
			left = mid + 1;
		}
		else {
			return mid;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	cout << binary_search(1, min(1000000000LL, 1LL * n * n));
}