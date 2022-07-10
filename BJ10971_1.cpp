#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 10000000;
int a[10], w[10][10];

// 시간복잡도 : O(N*(N-1)!) == O(N!)

// 기존과 달라진점
// 1-2-3-4, 2-3-4-1, 3-4-1-2, 4-1-2-3 모두 동일한 cost를 지불해야 한다.
// 즉 출발 지점을 1번째 도시로 지정해도 문제가 없다.

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}	
	
	int ans = MAX;
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}
	do {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int cost = w[a[i]][a[(i + 1) % n]];
			if (cost == 0) {
				sum = MAX;
				break;
			}
			else {
				sum += cost;
			}
		}
		ans = min(ans, sum);
	} while (next_permutation(a + 1, a + n));

	cout << ans;
	return 0;
}
