#include <iostream>
using namespace std;
int num[9];

// 시간복잡도 : O(2^N) (선택 문제)
// index라는 수를 선택했을 때와 하지 않았을 때를 모두 구현

void BT(int level, int index, int n, int m) {
	if (level == m + 1) {
		for (int i = 1; i <= m; i++) {
			cout << num[i] << ' ';
		}
		cout << '\n';
		return;
	}
	else if (index > n) {	// 아직 m개를 고르지 않았는데 더 이상 고를 수가 없는 경우
		return;
	}
	// 해당 숫자를 선택한 경우
	num[level] = index;
	BT(level + 1, index + 1, n, m);

	// 해당 숫자를 선택하지 않은 경우
	num[level] = 0;
	BT(level, index + 1, n, m);
}

int main() {
	int n, m;
	cin >> n >> m;
	BT(1, 1, n, m);
	return 0;
}