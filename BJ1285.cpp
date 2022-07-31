#include <iostream>
#include <cstring>
using namespace std;

// 시간복잡도 : O(2^n * n^2)

int main() {
	// 1. input
	int n;
	cin >> n;
	bool a[20][20];
	memset(a, false, sizeof(a));
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			if (str[j] == 'T') {
				a[i][j] = true;
			}
		}
	}
	
	// 2. sovle (bitmask & greedy)
	int ans = n * n;
	bool temp[20][20];
	for (int k = 0; k < (1 << n); k++) {	// 뒤집을 행 결정
		// 1. 원본 copy
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				temp[i][j] = a[i][j];
			}
		}
		
		// 2. 행 뒤집기
		for (int i = 0; i < n; i++) {
			if (k & (1 << i)) {
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