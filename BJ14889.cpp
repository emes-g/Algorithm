#include <iostream>
using namespace std;
const int MAX = 5000;
int start[10], link[10], s[20][20], ans = MAX;
bool check[20];

// index번째 선수의 start팀 합류 여부에만 초점을 맞춘 코드

void go(int level, int index, int n) {
	if (level == n / 2) {	// start팀이 완성된 경우
		int size = 0;
		for (int i = 0; i < n; i++) {
			if (!check[i]) {
				link[size++] = i;
			}
		}

		int total[2] = { 0 };
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				if (i != j) {
					total[0] += s[start[i]][start[j]];
					total[1] += s[link[i]][link[j]];
				}
			}
		}
		ans = min(ans, abs(total[0] - total[1]));
		return;
	}
	else if (index >= n) {
		return;
	}
	check[index] = true;
	start[level] = index;
	go(level + 1, index + 1, n);
	check[index] = false;
	start[level] = 0;
	go(level, index + 1, n);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}
	go(0, 0, n);
	cout << ans;
	return 0;
}