#include <iostream>
#include <vector>
using namespace std;
vector<int> r, c;
int h, w, n;

// <알고리즘>
// 1. 스티커 두 개를 고른다.
// 2. 고른 스티커에서 나올 수 있는 모든 경우의 수(4개)를 고려한다.
// 3. 두 스티커를 가로로 붙일지, 세로로 붙일지 고려한다.

bool good(int r1, int c1, int r2, int c2) {
	if ((max(r1, r2) <= h && c1 + c2 <= w) ||
		r1 + r2 <= h && max(c1, c2) <= w) {
		return true;
	}
	return false;
}

bool rotate(int r1, int c1, int r2, int c2) {
	if (good(r1, c1, r2, c2) || good(r1, c1, c2, r2) ||
		good(c1, r1, r2, c2) || good(c1, r1, c2, r2)) {
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	cin >> h >> w >> n;
	r.resize(n);
	c.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> r[i] >> c[i];
	}

	// 2. solve (brute force)
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (rotate(r[i], c[i], r[j], c[j])) {
				ans = max(ans, r[i] * c[i] + r[j] * c[j]);
			}
		}
	}
	cout << ans;
}