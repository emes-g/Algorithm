#include <iostream>
#include <vector>
using namespace std;
vector<int> a;
int c, p;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

// <문제 파악>
// 브루트 포스 그 자체

int calc() {
	int cnt = 0;
	switch (p) {
	case 1:
		cnt = c;
		for (int i = 0; i < c - 3; i++) {
			if (a[i] == a[i + 1] && a[i + 1] == a[i + 2] && a[i + 2] == a[i + 3]) {
				cnt++;
			}
		}
		break;
	case 2:
		for (int i = 0; i < c - 1; i++) {
			if (a[i] == a[i + 1]) {
				cnt++;
			}
		}
		break;
	case 3:
		for (int i = 0; i < c - 2; i++) {
			if (a[i] == a[i + 1] && a[i + 1] == a[i + 2] - 1) {
				cnt++;
			}
		}
		for (int i = 0; i < c - 1; i++) {
			if (a[i] == a[i + 1] + 1) {
				cnt++;
			}
		}
		break;
	case 4:
		for (int i = 0; i < c - 2; i++) {
			if (a[i] - 1 == a[i + 1] && a[i + 1] == a[i + 2]) {
				cnt++;
			}
		}
		for (int i = 0; i < c - 1; i++) {
			if (a[i] + 1 == a[i + 1]) {
				cnt++;
			}
		}
		break;
	case 5:
		for (int i = 0; i < c - 2; i++) {
			if (a[i] == a[i + 1] && a[i + 1] == a[i + 2]) {
				cnt++;
			}
			else if (a[i] == a[i + 1] + 1 && a[i + 1] + 1 == a[i + 2]) {
				cnt++;
			}
		}
		for (int i = 0; i < c - 1; i++) {
			if (a[i] + 1 == a[i + 1]) {
				cnt++;
			}
			else if (a[i] == a[i + 1] + 1) {
				cnt++;
			}
		}
		break;
	case 6:
		for (int i = 0; i < c - 2; i++) {
			if (a[i] == a[i + 1] && a[i + 1] == a[i + 2]) {
				cnt++;
			}
			else if (a[i] + 1 == a[i + 1] && a[i + 1] == a[i + 2]) {
				cnt++;
			}
		}
		for (int i = 0; i < c - 1; i++) {
			if (a[i] == a[i + 1]) {
				cnt++;
			}
			else if (a[i] == a[i + 1] + 2) {
				cnt++;
			}
		}
		break;
	case 7:
		for (int i = 0; i < c - 2; i++) {
			if (a[i] == a[i + 1] && a[i + 1] == a[i + 2]) {
				cnt++;
			}
			else if (a[i] == a[i + 1] && a[i + 1] == a[i + 2] + 1) {
				cnt++;
			}
		}
		for (int i = 0; i < c - 1; i++) {
			if (a[i] == a[i + 1]) {
				cnt++;
			}
			else if (a[i] + 2== a[i + 1]) {
				cnt++;
			}
		}
		break;
	}
	return cnt;
}
	

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> c >> p;
	a.resize(c);
	for (int i = 0; i < c; i++) {
		cin >> a[i];
	}
	cout << calc();
}