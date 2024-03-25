#include <iostream>
using namespace std;
bool a[20][20], temp[20][20];

// 시간복잡도 : O(2^n * n^2)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n, ans = 400;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			if (str[j] == 'T') {
				a[i][j] = true;
			}
		}
	}

	// 2. solve (bitmask & greedy)
	for (int s = 0; s < (1 << n); s++) {	// 뒤집을 행 결정
		// 1. 원본 copy
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				temp[i][j] = a[i][j];
			}
		}

		// 2. 행 뒤집기
		for (int i = 0; i < n; i++) {
			if (s & (1 << i)) {
				for (int j = 0; j < n; j++) {
					temp[i][j] = !temp[i][j];
				}
			}
		}

		// 3. 열 뒤집기
		int sum = 0;
		for (int j = 0; j < n; j++) {
			int t = 0;	// 해당 열에 있는 t의 개수
			for (int i = 0; i < n; i++) {
				if (temp[i][j]) {
					t++;
				}
			}
			sum += min(t, n - t);
		}
		ans = min(ans, sum);
	}
	cout << ans;
}
