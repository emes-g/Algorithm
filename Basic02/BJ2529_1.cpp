#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> ans;
char c[9];
bool check[10];

// <기존과 달라진 점>
// + : 중복되는 코드를 제거하여 코드가 간결해짐.

// - : 메모리와 시간이 추가로 필요하다.
// 기존 : 2020KB/8ms
// 신규 : 3576KB/8ms
// 왜?
// min, max만을 찾고 끝내던 기존과는 달리, 답 후보를 전부 찾고 min과 max만을 출력하기 때문이다.

bool good(char prev, char cur, char sign) {
	if (sign == '<') {
		if (prev > cur) {
			return false;
		}
	}
	else {
		if (prev < cur) {
			return false;
		}
	}
	return true;
}

void go(int level, string substr, int k) {
	if (level == k + 1) {
		ans.push_back(substr);
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (!check[i]) {
			if (level == 0 || good(substr[level - 1], i + '0', c[level - 1])) {
				check[i] = true;
				go(level + 1, substr + to_string(i), k);
				check[i] = false;
			}
		}
	}
}

int main() {
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> c[i];
	}

	go(0, "", k);

	sort(ans.begin(), ans.end());
	cout << ans[ans.size() - 1] << '\n';
	cout << ans[0] << '\n';
	return 0;
}
