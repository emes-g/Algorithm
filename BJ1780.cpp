#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> a;
int num[3];

bool good(int x1, int y1, int x2, int y2) {
	int val = a[x1][y1];
	for (int i = x1; i < x2; i++) {
		for (int j = y1; j < y2; j++) {
			if (a[i][j] != val) {
				return false;
			}
		}
	}
	num[val + 1]++;
	return true;
}

void go(int x1, int y1, int x2, int y2) {
	if (x2 - x1 == 1) {
		num[a[x1][y1] + 1]++;
		return;
	}
	else if (good(x1, y1, x2, y2)) {
		return;
	}
	int gap = (x2 - x1) / 3;
	for (int i = x1; i < x2; i += gap) {
		for (int j = y1; j < y2; j += gap) {
			go(i, j, i + gap, j + gap);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// 1. input
	int n;
	cin >> n;
	a.assign(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	// 2. solve (dnq)
	go(0, 0, n, n);

	// 3. output
	for (int i = 0; i < 3; i++) {
		cout << num[i] << '\n';
	}
}