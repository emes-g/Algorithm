#include <iostream>
#include <vector>
using namespace std;
const int MAX = 5000;
int start[10], link[10], s[20][20], ans = MAX;

// 기존과는 달리 link팀도 영입을 같이 하고 있기 때문에, 시간 측면에서 더 효율적이다.
// 시간 복잡도 : O(2^N)

void go(int first, int second, int index, int n) {
	if (first == n / 2 || second == n / 2) {
		if (first == n / 2) {
			for (int i = second; i < n / 2; i++) {
				link[i] = index++;
			}
		}
		else {
			for (int i = first; i < n / 2; i++) {
				start[i] = index++;
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
	start[first] = index;
	go(first + 1, second, index + 1, n);
	link[second] = index;
	go(first, second + 1, index + 1, n);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}
	go(0, 0, 0, n);
	cout << ans;
	return 0;
}
