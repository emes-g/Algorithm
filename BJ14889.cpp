#include <iostream>
using namespace std;
const int MAX = 5000;
int start[10], link[10], a[20][20], ans = MAX;

// 기존과는 달리 link팀도 영입을 같이 하고 있기 때문에, 시간 측면에서 더 효율적이다.
// 시간 복잡도 : O(2^N)

void go(int s, int l, int index, int n) {
	if (index >= n) {
		return;
	}
	else if (s == n / 2 || l == n / 2) {
		if (s == n / 2) {	// start팀이 먼저 꾸려진 경우
			for (int i = l; i < n / 2; i++) {
				link[i] = index++;
			}
		}
		else {	// link팀이 먼저 꾸려진 경우
			for (int i = s; i < n / 2; i++) {
				start[i] = index++;
			}
		}

		int total[2] = { 0 };
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				if (i != j) {
					total[0] += a[start[i]][start[j]];
					total[1] += a[link[i]][link[j]];
				}
			}
		}
		ans = min(ans, abs(total[0] - total[1]));
		return;
	}
	start[s] = index;
	go(s + 1, l, index + 1, n);
	link[l] = index;
	go(s, l + 1, index + 1, n);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	go(0, 0, 0, n);
	cout << ans;
	return 0;
}
