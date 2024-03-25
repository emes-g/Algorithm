#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 10001;
int cnt[MAX];

// 카운팅 정렬
// 시간 복잡도 : O(n)
// 공간 복잡도 : 숫자의 범위만큼
// → 속도가 빠른게 장점이지만, 그만큼 공간을 많이 차지할 수도 있다.
// → 수의 범위가 작을 때만 사용하라.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		cnt[num]++;
	}
	
	// 2. output
	for (int i = 1; i < MAX; i++) {
		while (cnt[i]--) {
			cout << i << '\n';
		}
	}
}