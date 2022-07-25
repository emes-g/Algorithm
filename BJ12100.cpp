#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, ans;

// <위로 밀어버린 예시>
// base			push			merge			push
// 2  4 16 8	2  4 16 8		2  8  16 8		2  8  16 8
// 8  4 0  0	8  4 2  0		8  0  4  0		8  16 4  0
// 16 8 2  0	16 8 2  0		16 16 0  0		16 0  0  0
// 2  8 2  0	2  8 0  0		2  0  0  0		2  0  0  0

void push(vector<vector<int>>& temp, int dir) {
	queue<int> q;
	switch (dir) {
	case 0:
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (temp[j][i]) {
					q.push(temp[j][i]);
					temp[j][i] = 0;
				}
			}

			int idx = 0;
			while (!q.empty()) {
				temp[idx++][i] = q.front();
				q.pop();
			}
		}
		break;
	case 1:
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				if (temp[j][i]) {
					q.push(temp[j][i]);
					temp[j][i] = 0;
				}
			}

			int idx = n - 1;
			while (!q.empty()) {
				temp[idx--][i] = q.front();
				q.pop();
			}
		}
		break;
	case 2:
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (temp[i][j]) {
					q.push(temp[i][j]);
					temp[i][j] = 0;
				}
			}

			int idx = 0;
			while (!q.empty()) {
				temp[i][idx++] = q.front();
				q.pop();
			}
		}
		break;
	case 3:
		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j >= 0; j--) {
				if (temp[i][j]) {
					q.push(temp[i][j]);
					temp[i][j] = 0;
				}
			}

			int idx = n - 1;
			while (!q.empty()) {
				temp[i][idx--] = q.front();
				q.pop();
			}
		}
		break;
	}
}

void merge(vector<vector<int>>& temp, int dir) {
	switch (dir) {
	case 0:
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < n; j++) {
				if (temp[j][i] == temp[j - 1][i]) {
					temp[j - 1][i] *= 2;
					temp[j][i] = 0;
				}
			}
		}
		break;
	case 1:
		for (int i = 0; i < n; i++) {
			for (int j = n - 2; j >= 0; j--) {
				if (temp[j][i] == temp[j + 1][i]) {
					temp[j + 1][i] *= 2;
					temp[j][i] = 0;
				}
			}
		}
		break;
	case 2:
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < n; j++) {
				if (temp[i][j] == temp[i][j - 1]) {
					temp[i][j - 1] *= 2;
					temp[i][j] = 0;
				}
			}
		}
		break;
	case 3:
		for (int i = 0; i < n; i++) {
			for (int j = n - 2; j >= 0; j--) {
				if (temp[i][j] == temp[i][j + 1]) {
					temp[i][j + 1] *= 2;
					temp[i][j] = 0;
				}
			}
		}
		break;
	}
}

void go(int level, vector<vector<int>> a) {
	if (level == 5) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				ans = max(ans, a[i][j]);
			}
		}
		return;
	}
	vector<vector<int>> temp(n, vector<int>(n));
	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				temp[i][j] = a[i][j];
			}
		}
		push(temp, k);
		merge(temp, k);
		push(temp, k);
		go(level + 1, temp);
	}
}

int main() {
	// 1. input
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	
	// 2. solve (brute force)
	go(0, a);
	cout << ans;
}