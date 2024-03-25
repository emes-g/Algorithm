#include <iostream>
using namespace std;
typedef long long ll;
int n, m, a[10001];

// <문제 파악>
// N이 20억이라는 것부터 이미 순차 탐색은 불가능한 상황이며,
// '특정 분까지 몇 명이 놀이기구에 탑승했었는지'는 이분 탐색으로 구할 수 있는 상황

ll calc(ll mid) {	// mid분까지 놀이기구에 탄 애들의 수
	ll cnt = m;
	for (int i = 1; i <= m; i++) {
		cnt += mid / a[i];
	}
	return cnt;
}

int binary_search(ll left, ll right) {
	if (n <= m) {	// 애들의 수보다 놀이기구의 수가 많은 경우
		return n;
	}
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll p1 = calc(mid);
		ll p2 = calc(mid + 1);
		if (n <= p1) {
			right = mid - 1;
		}
		else if (n > p2) {
			left = mid + 1;
		}
		else {	// 마지막 아이는 (mid + 1)분에 놀이기구에 탑승하게 된다.
			for (int i = 1; i <= m; i++) {
				if ((mid + 1) % a[i] == 0) {
					if (++p1 == n) {
						return i;
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int MAX = 1;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
		MAX = max(MAX, a[i]);
	}

	// 2. solve (binary_search)
	cout << binary_search(0, 1LL * n * MAX);	// 애들의 수 * 놀이기구 중 가장 긴 운행 시간
}