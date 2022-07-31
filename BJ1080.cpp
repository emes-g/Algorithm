#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;

// 좌상단 일부 직사각형은 무조건 같게 만들 수 있으므로,
// 남은 영역만 비교해주면 된다.

void toggle(vector<vector<bool>>& vec, int x, int y) {
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			vec[i][j] = !vec[i][j];
		}
	}
}

void input(vector<vector<bool>>& vec) {
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			if (str[j] - '0') {
				vec[i][j] = true;
			}
		}
	}
}

bool good(vector<vector<bool>>& a, vector<vector<bool>>& b) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	// 1. input
	cin >> n >> m;
	vector<vector<bool>> a(n, vector<bool>(m)), b(n, vector<bool>(m));
	input(a);
	input(b);
	if (n < 3 || m < 3) {
		cout << (good(a, b) ? 0 : -1);
		return 0;
	}

	// 2. solve
	int ans = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (a[i][j] != b[i][j]) {
				ans++;
				toggle(a, i, j);
			}
		}
	}
	cout << (good(a, b) ? ans : -1);
}