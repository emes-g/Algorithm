#include <iostream>
#include <climits>
using namespace std;
int a[401][801], s[401][801], n, ans;

// <알고리즘>
// 1. 모든 단위 삼각형에 대해 해당 단위 삼각형에서 시작하는 부분 삼각형의 합을 구한다.
// 2. 해당 값이 최댓값이라면 갱신한다.

bool good(int row, int l, int r) {
	return (l >= 1 && r <= 2 * row - 1) && (row >= 1 && row <= n);
}

void go(int row, int l, int r, int sum) {
	if (good(row, l, r)) {
		sum += s[row][r] - s[row][l - 1];
		ans = max(ans, sum);
		if (l % 2 == 0) {	// l이든 r이든 짝수라면
			go(row - 1, l - 2, r, sum);
		}
		else {
			go(row + 1, l, r + 2, sum);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while (true) {
		// 1. input
		cin >> n;
		if (n == 0) {
			break;
		}
		ans = INT_MIN;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 2 * i - 1; j++) {
				cin >> a[i][j];
				s[i][j] = s[i][j - 1] + a[i][j];
			}
		}

		// 2. solve (brute force)
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 2 * i - 1; j++) {
				go(i, j, j, 0);
			}
		}
		cout << t++ << ". " << ans << '\n';
	}
}