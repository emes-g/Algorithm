#include <iostream>
using namespace std;
int a[8];

// 시간복잡도 : O(N!) (순서 문제)
// start가 있으므로 check가 필요하지 않음.

void go(int level, int start, int n, int m) {
	if (level == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = start; i <= n; i++) {
		a[level] = i;
		go(level + 1, i + 1, n, m);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	go(0, 1, n, m);
}
