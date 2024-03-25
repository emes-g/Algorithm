#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
int n, m, h, garo[30][10];

// <문제 파악>
// 선을 3개까지 추가할 수 있는 사다리 게임 (브루트 포스)
// 최악 시간 복잡도 : O(((N-1)*H)^3) * O(NM)
// But 실제로는 선분을 연속하도록 배치할 수 없고, 도중에 제어되는 경우가 많기 때문에
// 시간은 훨씬 적게 걸릴 것이다.

// <주의 사항>
// 해당 문제에서는 행과 열을 1번부터 사용한다.
// 근데 내가 행과 열을 1이 아닌 0부터 사용하고자 한다면, 
// 입력을 받을 때 행과 열 역시 하나씩 줄여서 입력받아야 한다.

bool straight(int c) {	// 특정 열에서 시작해서 동일한 열에서 끝나는지 검사
	int cur = c;
	for (int i = 0; i < h; i++) {
		switch (garo[i][cur]) {
		case 1:
			cur++;
			break;
		case 2:
			cur--;
			break;
		}
	}
	return cur == c;
}

bool go() {	// 모든 열이 동일한 열에서 끝나는지 검사
	for (int i = 0; i < n; i++) {
		if (!straight(i)) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> h;
	while (m--) {
		int x, y;
		cin >> x >> y;
		garo[x - 1][y - 1] = 1;
		garo[x - 1][y] = 2;
	}

	// 1. 선분을 놓을 수 있는 위치를 a에 저장
	vector<pair<int, int>> a;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (garo[i][j] != 0 || garo[i][j + 1] != 0) {
				continue;
			}
			a.push_back({ i,j });
		}
	}

	// 2. 선분을 추가로 놓지 않은 경우
	if (go()) {
		cout << 0;
		return 0;
	}

	// 3. 선분을 추가로 놓은 경우
	int ans = 4, s = a.size();
	for (int i = 0; i < s; i++) {	// 1개
		int x1, y1;
		tie(x1, y1) = a[i];
		garo[x1][y1] = 1;
		garo[x1][y1 + 1] = 2;
		if (go()) {
			cout << 1;
			return 0;
		}
		for (int j = i + 1; j < s; j++) {	// 2개
			int x2, y2;
			tie(x2, y2) = a[j];
			if (garo[x2][y2] != 0 || garo[x2][y2 + 1] != 0) {
				continue;
			}
			garo[x2][y2] = 1;
			garo[x2][y2 + 1] = 2;
			if (go()) {
				ans = min(ans, 2);
			}
			for (int k = j + 1; k < s; k++) {	// 3개
				int x3, y3;
				tie(x3, y3) = a[k];
				if (garo[x3][y3] != 0 || garo[x3][y3 + 1] != 0) {
					continue;
				}
				garo[x3][y3] = 1;
				garo[x3][y3 + 1] = 2;
				if (go()) {
					ans = min(ans, 3);
				}
				garo[x3][y3] = 0;
				garo[x3][y3 + 1] = 0;
			}
			garo[x2][y2] = 0;
			garo[x2][y2 + 1] = 0;
		}
		garo[x1][y1] = 0;
		garo[x1][y1 + 1] = 0;
	}
	cout << (ans == 4 ? -1 : ans);
}