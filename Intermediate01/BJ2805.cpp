#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> a;

// 랜선 자르기(1654) easy ver.
// 결정 문제의 답이 이분적인 전형적인 이분 탐색 문제

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
	
	// 1. input
	cin >> n >> m;
	a.resize(n);
	int right = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		right = max(right, a[i]);
	}
	
	// 2. solve (binary_search)
	cout << binary_search(1, right);
}
