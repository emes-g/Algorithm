#include <iostream>
using namespace std;
int s[4][4];

int main() {
	// 1. input
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			s[i][j] = str[j] - '0';
		}
	}

	// 2. solve (bitmask)
	for (int sub = 0; sub < (1 << n * m); sub++) {	// 가능한 모든 경우에 대해서
		int sum = 0;
		for (int i = 0; i < n; i++) {	// 모든 행에 대해서
			int cur = 0;
			for (int j = 0; j < m; j++) {	// 해당 행의 모든 칸에 대해서
				if ((sub & (1 << i * m + j)) == 0) {	// 해당 칸이 가로면
					cur = cur * 10 + s[i][j];
				}
				else {
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}

		for (int i = 0; i < m; i++) {	// 모든 열에 대해서
			int cur = 0;
			for (int j = 0; j < n; j++) {	// 해당 열의 모든 칸에 대해서
				if ((sub & (1 << j * m + i)) != 0) {	// 해당 칸이 세로면
					cur = cur * 10 + s[j][i];
				}
				else {
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}
		ans = max(ans, sum);
	}

	// 3. output
	cout << ans;
	return 0;
}
