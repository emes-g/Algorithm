#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool ok;

// 시간 초과
// ∵ 모든 레벨에 대하여 가능한 모든 순열을 해 보기 때문

bool check_area(vector<vector<int>>& temp, int row, int col) {
	// 1. 세로 확인
	bool check[10] = { 0, };
	for (int i = 0; i < 9; i++) {
		int num = temp[i][col];
		if (check[num] && num != 0) {
			return false;
		}
		check[num] = true;
	}
	// 2. 3*3 확인
	fill_n(check, 10, false);
	for (int i = row - row % 3; i < row - row % 3 + 3; i++) {
		for (int j = col - col % 3; j < col - col % 3 + 3; j++) {
			int num = temp[i][j];
			if (check[num] && num != 0) {
				return false;
			}
			check[num] = true;
		}
	}
	return true;
}

void go(int level, vector<vector<int>> a) {
	if (level == 9) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
		ok = true;
		return;
	}
	// 1. 가로 줄을 읽는다.
	bool check[10] = { 0, };
	for (int i = 0; i < 9; i++) {
		check[a[level][i]] = true;
	}
	// 2. 없는 숫자를 찾는다.
	vector<int> empty;
	for (int i = 1; i < 10; i++) {
		if (!check[i]) {
			empty.push_back(i);
		}
	}
	sort(empty.begin(), empty.end());
	// 3. 가능한 경우를 모두 해 본다.
	vector<vector<int>> temp(9, vector<int>(9));
	do {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				temp[i][j] = a[i][j];
			}
		}
		int idx = 0;
		for (int i = 0; i < 9; i++) {
			if (!temp[level][i]) {
				temp[level][i] = empty[idx++];
				if (!check_area(temp, level, i)) {
					break;
				}
			}
			if (i == 8) {
				go(level + 1, temp);
				if (ok) {
					return;
				}
			}
		}
	} while (next_permutation(empty.begin(), empty.end()));
}

int main() {
	vector<vector<int>> a(9, vector<int>(9));
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> a[i][j];
		}
	}
	go(0, a);
}
