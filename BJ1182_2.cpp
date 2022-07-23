#include <iostream>
using namespace std;
int a[20], ans;

// input
// 5 0
// 2 -2 0 3 -3

// <문제점 개선>
// 비트마스크 버전 말고, 기존 재귀 버전에서 왜 안됐는지 생각해보면
// 0에서 ans++하고 해당 재귀를 return으로 종료시켰기 때문
// (0 뒤에 있는 3, -3 포함하면 추가 경우의 수가 나옴에도 불구하고)

void go(int index, int sum, int n, int s) {
	if (index == n) {
		if (sum == s) {
			ans++;
		}
		return;
	}
	go(index + 1, sum + a[index], n, s);
	go(index + 1, sum, n, s);
}

int main() {
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	go(0, 0, n, s);
	if (s == 0) {	// 아무것도 선택하지 않은 경우 제거
		ans -= 1;
	}
	cout << ans;
	return 0;
}