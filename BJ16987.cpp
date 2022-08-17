#include <iostream>
#include <vector>
using namespace std;
int s[8], w[8], n, ans;

// 시간 복잡도 : O((N-1)^N)

// <참고 사항>
// 1. 정렬이 필요한 문제가 아니므로 굳이 입력을 pair로 받을 필요가 없다.

void go(int index) {
	if (index >= n) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] <= 0) {
				cnt++;
			}
		}
		ans = max(ans, cnt);
		return;
	}
	else if (s[index] <= 0) {	// 계란이 깨진 경우
		go(index + 1);
		return;
	}
	bool ok = false;
	for (int i = 0; i < n; i++) {	// 최대 (N-1)개가 안 깨진 상태로 존재 가능
		if (i != index && s[i] > 0) {
			ok = true;
			s[i] -= w[index];
			s[index] -= w[i];
			go(index + 1);
			s[i] += w[index];
			s[index] += w[i];
		}
	}
	if (!ok) {	// 현재 들고 있는 계란을 제외하고 모두 깨져 있는 경우
		go(index + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> w[i];
	}
	
	// 2. solve (brute force)
	go(0);
	cout << ans;
}