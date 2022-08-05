#include <iostream>
#include <vector>
using namespace std;
vector<vector<bool>> a;

void tree(int x, int y) {
	a[x][y + 2] = true;
	a[x + 1][y + 1] = true;
	a[x + 1][y + 3] = true;
	for (int i = 0; i < 5; i++) {
		a[x + 2][y + i] = true;
	}
}

void go(int n, int x, int y) {
	if (n == 3) {
		tree(x, y);
		return;
	}
	go(n / 2, x, y + n / 2);
	go(n / 2, x + n / 2, y);
	go(n / 2, x + n / 2, y + n);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	a.assign(n, vector<bool>(2 * n));
	go(n, 0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			cout << (a[i][j] ? '*' : ' ');
		}
		cout << '\n';
	}
}