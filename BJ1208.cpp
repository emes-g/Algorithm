#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[40];

// <문제 파악>
// 비트마스크를 활용하여 가능한 모든 부분수열 확인
// But 문제는 N이 40이라 TLE 발생
// → '중간에서 만나기' 기법을 이용해 문제를 반으로 나눠서 해결

// 시간복잡도 : O(TlogT), T=2^(N/2)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// 2. solve (meet in the middle)
	m = n / 2;
	n -= m;
	vector<int> x(1 << n);
	for (int k = 0; k < (1 << n); k++) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (k & (1 << i)) {
				sum += a[i];
			}
		}
		x[k] = sum;
 	}
	vector<int> y(1 << m);
	for (int k = 0; k < (1 << m); k++) {
		int sum = 0;
		for (int i = 0; i < m; i++) {
			if (k & (1 << i)) {
				sum += a[n + i];
			}
		}
		y[k] = sum;
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end(), greater<int>());
	long long i = 0, j = 0, ans = 0;
	int X = x.size(), Y = y.size();
	while (i < X && j < Y) {
		int sum = x[i] + y[j];
		if (sum < s) {
			i++;
		}
		else if (sum > s) {
			j++;
		}
		else {
			int idx1 = i + 1, idx2 = j + 1;
			while (idx1 < X && x[idx1] == x[i]) {
				idx1++;
			}
			while (idx2 < Y && y[idx2] == y[j]) {
				idx2++;
			}
			ans += (idx1 - i) * (idx2 - j);
			i = idx1;
			j = idx2;
		}
	}
	cout << (s == 0 ? ans - 1 : ans);
}