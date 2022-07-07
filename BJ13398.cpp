#include <iostream>
using namespace std;
const int SIZE = 100000;
const int MIN = -100000000;
int a[SIZE + 1], l[SIZE + 1], r[SIZE + 1];

// l[n] : 왼쪽에서부터 카운트할 때, a[n]을 포함하는 최대 연속합
// r[n] : 오른쪽에서부터 카운트할 때, a[n]을 포함하는 최대 연속합

// <유사 문제>
// 가장 긴 바이토닉 부분 수열 (11054)

// <주의 사항>
// 기준을 정해서 변수로 두고 한 칸씩 옮기면 O(N^2)이므로 풀 수 없다.
// 기준을 변수로 두면 안 된다!

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// 1. input
	int n, ans = MIN;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		l[i] = r[i] = a[i];
	}

	// 2. solve (dp)
	for (int i = 2; i <= n; i++) {
		l[i] = max(l[i], l[i - 1] + a[i]);
	}
	for (int i = n - 1; i >= 1; i--) {
		r[i] = max(r[i], r[i + 1] + a[i]);
	}

	// 3. output
	for (int i = 1; i <= n; i++) {
		if (ans < l[i]) {
			ans = l[i];
		}
	}
	for (int i = 1; i < n; i++) {
		if (ans < l[i - 1] + r[i + 1]) {
			ans = l[i - 1] + r[i + 1];
		}
	}
	cout << ans;
	return 0;
}