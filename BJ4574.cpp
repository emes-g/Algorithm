#include <iostream>
#include <cstring>
using namespace std;
int a[9][9];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool ok, check[10][10];	// 해당 pair의 사용 여부

// 스도쿠(2580) + α
// 사용한 함수가 완전히 동일함

// <궁금한 점>
// 왜 스도쿠보다 훨씬 빠르지?
// 스도쿠 : 2020kb/228ms
// 스도미노쿠 : 2024kb/4ms

void print() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << a[i][j];
		}
		cout << '\n';
	}
}

void init() {
	memset(a, 0, sizeof(a));
	memset(check, false, sizeof(check));
	ok = false;
}

bool good(int x, int y, int num) {
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
		ok = true;
		return;
	}
	else if (y == 9) {
		go(x + 1, 0);
	}
	if (!a[x][y]) {
		for (int i = 1; i < 10; i++) {
			if (good(x, y, i)) {
				a[x][y] = i;
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (nx >= 0 && nx < 9 && ny >= 0 && ny < 9) {
						if (!a[nx][ny]) {
							for (int j = 1; j < 10; j++) {
								if (good(nx, ny, j)) {
									a[nx][ny] = j;
									if (check[a[x][y]][a[nx][ny]]) {	// 사용한 pair라면
										a[nx][ny] = 0;
										continue;
									}
									else {
										check[a[x][y]][a[nx][ny]] = check[a[nx][ny]][a[x][y]] = true;
										go(x, y + 1);
										check[a[x][y]][a[nx][ny]] = check[a[nx][ny]][a[x][y]] = false;
										a[nx][ny] = 0;
										if (ok) {
											return;
										}
									}
								}
							}
						}
					}
				}
				a[x][y] = 0;
			}
		}
	}
	else {
		go(x, y + 1);
	}
}

int main() {
	int t = 1;
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			return 0;
		}
		for (int i = 0; i < n; i++) {
			int x, y;
			string str;
			cin >> x >> str;
			a[str[0] - 'A'][str[1] - '1'] = x;
			cin >> y >> str;
			a[str[0] - 'A'][str[1] - '1'] = y;
			check[x][y] = check[y][x] = true;
		}
		for (int i = 1; i < 10; i++) {
			string str;
			cin >> str;
			a[str[0] - 'A'][str[1] - '1'] = i;
		}
		cout << "Puzzle " << t++ << '\n';
		go(0, 0);
		init();
	}
}
