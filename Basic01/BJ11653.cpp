#include <iostream>
using namespace std;

// n = a * b인 합성수라고 하자. (a >= √n)
// 그러면 항상 √n보다 작거나 같은 특정 인수가 조건*을 만족하게 된다. (b <= √n → 조건* 만족)
// 그러므로 i<=√n의 범위만 파악해주면 된다.

// 만약 조건*에 걸리지 않는다고 하면 n은 더 이상 합성수가 아니게 된다.
// 즉 조건*에 걸리지 않는 경우 n은 소수이므로, 해당 n만 한 번 더 출력해주면 된다.

int main() {
	int n;
	cin >> n;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {	// *
			cout << i << '\n';
			n /= i;
		}
	}
	if (n > 1) {
		cout << n;
	}
	return 0;
}
