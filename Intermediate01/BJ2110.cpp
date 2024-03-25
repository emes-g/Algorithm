#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, c;
vector<int> a;

// 결정 문제 : 가장 인접한 두 공유기 사이의 거리가 mid여도 되는가?

// 첫 집은 공유기를 무조건 설치하는게 좋다!

bool good(int mid) {
	int last = a[0], cnt = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] - last >= mid) {
			last = a[i];
			cnt++;
		}
	}
	return cnt < c;
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

	cin >> n >> c;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	cout << binary_search(0, a[n - 1] - a[0]);
}
