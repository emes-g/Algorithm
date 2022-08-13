#include <iostream>
using namespace std;
bool check[1001];
int n, ans;
int a[4] = { 1,5,10,50 };

// <문제 파악>
// 순서가 중요하지 않은 선택 문제
// (단, 같은 것을 선택할 수도 있다는 점에 유념)

// 유사 : N과 M(8) (15657)

void go(int level, int index, int sum) {
	if (level == n) {
		if (!check[sum]) {
			check[sum] = true;
			ans++;
		}
		return;
	}
	for (int i = index; i < 4; i++) {
		go(level + 1, i, sum + a[i]);
	}
}

int main() {
	cin >> n;
	go(0, 0, 0);
	cout << ans;
}
