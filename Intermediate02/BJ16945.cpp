#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
int a[10], b[10], ans = 100;
pii g[4] = { {1,9},{2,8},{3,7},{4,6} };
bool check[4];

// <문제 파악>
// 매직 스퀘어의 특성
// 1. 임의의 가로, 세로, 대각선 합이 15이다.
// 2. 중심값은 항상 5이다.

// 시간복잡도 : O(4! * 2^4) * O(good())

bool good() {
	for (int i = 0; i < 3; i++) {
		int r = 0;	// 해당 행의 합 (가로)
		int c = 0;	// 해당 열의 합 (세로)
		for (int j = 0; j < 3; j++) {
			r += b[3 * i + j];
			c += b[3 * j + i];
		}
		if (r != 15 || c != 15) {
			return false;
		}
	}
	return true;
}

void go(int level) {
	if (level == 4 && good()) {
		int sum = 0;
		for (int i = 0; i < 9; i++) {
			sum += abs(a[i] - b[i]);
		}
		ans = min(ans, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (!check[i]) {
			check[i] = true;
			b[level] = g[i].first;
			b[8 - level] = g[i].second;
			go(level + 1);
			swap(b[level], b[8 - level]);
			go(level + 1);
			check[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// 1. input
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
	}

	// 2. solve (brute force)
	b[4] = 5;
	go(0);
	cout << ans;
}