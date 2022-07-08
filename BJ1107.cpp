#include <iostream>
#include <string>
using namespace std;
const int IMPOSSIBLE = 1000000;

int main() {
	// 1. input
	int n, m, ans = IMPOSSIBLE;
	cin >> n >> m;
	bool btn[10];
	fill_n(btn, 10, true);
	while (m--) {
		int num;
		cin >> num;
		btn[num] = false;
	}

	// 2. solve (brute force)
	int num[3], click[3];
	fill_n(num, 2, IMPOSSIBLE);
	num[2] = 100;
	for (int i = n; i >= 0; i--) {	// get num[0]
		int temp = i;
		while (temp != 0) {
			if (btn[temp % 10]) {
				temp /= 10;
			}
			else {
				break;
			}
		}
		if (temp == 0 && btn[0]) {
			num[0] = i;
			break;
		}
	}
	for (int i = n; i <= IMPOSSIBLE; i++) {	// get num[1]
		int temp = i;
		while (temp != 0) {
			if (btn[temp % 10]) {
				temp /= 10;
			}
			else {
				break;
			}
		}
		if (temp == 0 && btn[0]) {
			num[1] = i;
			break;
		}
	}

	// 3. output
	click[0] = to_string(num[0]).size() + abs(num[0] - n);
	click[1] = to_string(num[1]).size() + abs(num[1] - n);
	click[2] = abs(num[2] - n);
	for (int i = 0; i < 3; i++) {
		ans = min(ans, click[i]);
	}
	cout << ans;
	return 0;
}