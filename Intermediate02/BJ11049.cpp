#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 501;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n, temp;
	cin >> n;
	vector<int> d(n + 1);
	cin >> d[0] >> d[1];
	for (int i = 2; i <= n; i++) {
		cin >> temp >> d[i];
	}

	// 2. solve
	int c[SIZE][SIZE];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				c[i][i] = 0;
			}
			else {
				c[i][j] = -1;
			}
		}
	}
	for (int L = 1; L <= n - 1; L++) {
		for (int i = 1; i <= n - L; i++) {
			int j = i + L;
			for (int k = i; k <= j - 1; k++) {
				temp = c[i][k] + c[k + 1][j] + d[i - 1] * d[k] * d[j];
				if (c[i][j] == -1 || temp < c[i][j]) {
					c[i][j] = temp;
				}
			}
		}
	}
	cout << c[1][n];
}