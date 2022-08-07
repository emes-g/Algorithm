#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> a;

// 랜선 자르기(1654) easy ver.

bool good(int mid) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > mid) {
			sum += a[i] - mid;
		}
	}
	return sum < m;
}

int binary_search(int left, int right) {
	while (left <= right) {
		int mid = (left + right) / 2;
		if (good(mid)) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return right;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	a.resize(n);
	int right = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		right = max(right, a[i]);
	}
	cout << binary_search(1, right);
}