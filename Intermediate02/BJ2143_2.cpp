#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1000;
int a[MAX], b[MAX];

// algorithm::equal_range(it first, it last, value)
// 구간 [first, last)에서 value의 lower_bound와 upper_bound를 pair로 반환
// → 두 반환값의 차의 절댓값이 해당 원소(value)의 개수

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int t, n, m;
	cin >> t >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	// 2. solve (binary search)
	int sum;
	vector<int> x, y;
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = i; j < n; j++) {
			sum += a[j];
			x.push_back(sum);
		}
	}
	for (int i = 0; i < m; i++) {
		sum = 0;
		for (int j = i; j < m; j++) {
			sum += b[j];
			y.push_back(sum);
		}
	}
	sort(y.begin(), y.end());

	long long ans = 0;
	for (int i = 0; i < x.size(); i++) {
		auto it = equal_range(y.begin(), y.end(), t - x[i]);
		ans += it.second - it.first;
	}
	cout << ans;
}