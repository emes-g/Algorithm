#include <iostream>
#include <vector>
using namespace std;
int w[10], ans = 0;
bool check[10];

// 시간복잡도 : O((N-2)!)

void go(int level, int e, int n) {
	if (level == n - 2) {
		ans = max(ans, e);
		return;
	}
	for (int i = 1; i < n - 1; i++) {
		if (!check[i]) {
			int prev, next;
			check[i] = true;
			for (int j = i - 1; j >= 0; j--) {
				if (!check[j]) {
					prev = w[j];
					break;
				}
			}
			for (int j = i + 1; j < n; j++) {
				if (!check[j]) {
					next = w[j];
					break;
				}
			}
			go(level + 1, e + prev * next, n);
			check[i] = false;
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	go(0, 0, n);
	cout << ans;
}