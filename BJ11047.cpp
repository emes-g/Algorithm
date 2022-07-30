#include <iostream>
#include <algorithm>
using namespace std;
int a[10];

// 기준 : 가장 큰 단위를 가진 지폐부터 사용해 본다. (현재 가장 최적인 선택)

// 이전의 선택과 관련 없이 현재 상태에서 최선의 결과를 선택하여 최적의 결과를 낼 수 있다.
// → 그리디 알고리즘

int main() {
	// 1. input
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// 2. solve (greedy)
	int idx = 0, ans = 0;
	sort(a, a + n, greater<int>());
	while (k != 0) {
		ans += k / a[idx];
		k -= (k / a[idx]) * a[idx];
		idx++;
	}
	cout << ans;
}