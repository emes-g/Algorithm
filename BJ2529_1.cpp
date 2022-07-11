#include <iostream>
using namespace std;
char c[9];
bool ok, check[10];
int a[10];

// 백트래킹

void init() {
	ok = false;
	fill_n(check, 10, false);
}

void go(int level, int prev, int k, bool maximum) {
	if (level == 0) {
		if (maximum) {
			for (int i = 9; i >= 0; i--) {
				check[i] = true;
				a[level] = i;
				go(1, i, k, true);
				check[i] = false;
				if (ok) {
					return;
				}
			}
		}
		else {
			for (int i = 0; i < 10; i++) {
				check[i] = true;
				a[level] = i;
				go(1, i, k, false);
				check[i] = false;
				if (ok) {
					return;
				}
			}
		}
	}
	else if (level == k + 1) {
		for (int i = 0; i < k + 1; i++) {
			cout << a[i];
		}
		cout << '\n';
		ok = true;
		return;
	}
	else {
		if (maximum) {
			if (c[level - 1] == '<') {
				for (int i = 9; i > prev; i--) {
					if (!check[i]) {
						check[i] = true;
						a[level] = i;
						go(level + 1, i, k, maximum);
						check[i] = false;
						if (ok) {
							return;
						}
					}
				}
			}
			else {
				for (int i = prev - 1; i >= 0; i--) {
					if (!check[i]) {
						check[i] = true;
						a[level] = i;
						go(level + 1, i, k, maximum);
						check[i] = false;
						if (ok) {
							return;
						}
					}
				}
			}
		}
		else {
			if (c[level - 1] == '<') {
				for (int i = prev + 1; i < 10; i++) {
					if (!check[i]) {
						check[i] = true;
						a[level] = i;
						go(level + 1, i, k, maximum);
						check[i] = false;
						if (ok) {
							return;
						}
					}
				}
			}
			else {
				for (int i = 0; i < prev; i++) {
					if (!check[i]) {
						check[i] = true;
						a[level] = i;
						go(level + 1, i, k, maximum);
						check[i] = false;
						if (ok) {
							return;
						}
					}
				}
			}
		}
	}
}

int main() {
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> c[i];
	}
	go(0, 0, k, true);
	init();
	go(0, 0, k, false);
	return 0;
}
