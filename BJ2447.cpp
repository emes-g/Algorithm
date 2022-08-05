#include <iostream>
#include <vector>
using namespace std;
vector<vector<bool>> a;

// <자료형 관련>
// vector<bool>은 한 칸이 1비트를 차지하지만,
// bool 배열은 한 칸이 1바이트를 차지한다.

void star(int x, int y) {
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			if (i == x + 1 && j == y + 1) {
				continue;
			}
			a[i][j] = true;
		}
	}
}

void go(int n, int x, int y) {
	if (n == 3) {
		star(x, y);
		return;
	}
	for (int i = x; i < x + n; i += n / 3) {
		for (int j = y; j < y + n; j += n / 3) {
			if (i == x + n / 3 && j == y + n / 3) {
				continue;
			}
			go(n / 3, i, j);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	a.assign(n, vector<bool>(n));
	go(n, 0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << (a[i][j] ? '*' : ' ');
		}
		cout << '\n';
	}
}