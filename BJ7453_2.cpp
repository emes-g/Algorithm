#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 4000;
int a[MAX], b[MAX], c[MAX], d[MAX];

// 시간복잡도 : O(N^2 * log(N^2))

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	// 2. solve (meet in the middle & binary search)
	vector<int> x, y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			x.push_back(a[i] + b[j]);
			y.push_back(c[i] + d[j]);
		}
	}
	sort(y.begin(), y.end());

	ll ans = 0;
	for (int i = 0; i < x.size(); i++) {
		auto it = equal_range(y.begin(), y.end(), -x[i]);
		ans += it.second - it.first;
	}
	cout << ans;
}