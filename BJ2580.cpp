#include <iostream>
using namespace std;
int a[9][9];

// 상태복구를 하지 않으면, 유망성 검사에서 이전에 할당했던 값을 사용하게 된다.
// 2020kb/228ms

void print() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}

bool good(int x, int y, int num) {	// 유망성 검사 (해당 위치에 해당 숫자가 괜찮은지)
	for (int i = 0; i < 9; i++) {
		if (a[x][i] == num) {	// 가로
			return false;
		}
		if (a[i][y] == num) {	// 세로
			return false;
		}
	}
	for (int i = x - x % 3; i < x - x % 3 + 3; i++) {	// 3 * 3
		for (int j = y - y % 3; j < y - y % 3 + 3; j++) {
			if (a[i][j] == num) {
				return false;
			}
		}
	}
	return true;
}

void go(int x, int y) {
	if (x == 9) {
		print();
		exit(0);
	}
	else if (y == 9) {
		go(x + 1, 0);
	}
	if (!a[x][y]) {
		for (int i = 1; i < 10; i++) {
			if (good(x, y, i)) {
				a[x][y] = i;
				go(x, y + 1);
				a[x][y] = 0;	// 이전 상태로 돌려주어야 한다. (상태 복구)
			}
		}
	}
	else {
		go(x, y + 1);
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> a[i][j];
		}
	}
	go(0, 0);
}