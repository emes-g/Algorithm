#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000000000;
typedef long long ll;
int n;
vector<int> a;

// <삼분 탐색 / 정수>
// 한 번에 답을 구할 수 있는 실수와는 달리,
// 정수의 경우에는 삼분 탐색을 통해 근사 범위만 구해놓고
// 이후 브루트 포스로 정확한 값을 찾는다.

// 시간복잡도 : O(n * log(1e9))

ll dist(ll gap) {
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += abs(i * gap - a[i]);
	}
	return sum;
}

ll ternary_search(int left, int right) {
	// for(int i=0; i<100; i++)로 구현해도 무방
	while (right - left >= 3) {
		int m1 = left + (right - left) / 3;
		int m2 = right - (right - left) / 3;
		ll d1 = dist(m1);
		ll d2 = dist(m2);
		if (d1 < d2) {
			right = m2;
		}
		else {
			left = m1;
		}
	}
	ll ans = dist(right);
	for (int i = left; i < right; i++) {
		ans = min(ans, dist(i));
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << ternary_search(0, MAX);
}
