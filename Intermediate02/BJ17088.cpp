#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100001;

// <문제 파악>
// 등차수열의 성질을 이용한 브루트 포스 문제
// an = a1 + (n-1)d
// (이때 d = a2 - a1)

// <주의사항>
// 주어진 배열을 정렬해서는 안 된다.
// 어디에도 정렬하라는 문구가 쓰여있지 않다!

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// 1. input
	int n;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	if (n == 1) {
		cout << 0;
		return 0;
	}

	// 2. solve
	vector<int> a(n);
	int ans = MAX;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			a[0] = num[0] + i;
			a[1] = num[1] + j;
			int cnt = abs(i) + abs(j);
			int d = a[1] - a[0];
			bool good = true;
			for (int k = 2; k < n; k++) {
				a[k] = a[k - 1] + d;
				if (a[k] == num[k]) {
					continue;
				}
				else if (a[k] == num[k] - 1 || a[k] == num[k] + 1) {
					cnt++;
				}
				else {
					good = false;
					break;
				}
			}
			if (good) {
				ans = min(ans, cnt);
			}
		}
	}
	cout << (ans == MAX ? -1 : ans);
}