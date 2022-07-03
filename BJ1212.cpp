#include <iostream>
#include <string>
using namespace std;

int main() {
	string oct;
	cin >> oct;
	bool start = false;

	for (int i = 0; i < oct.size(); i++) {
		int num = oct[i] - '0';
		for (int j = 4; j >= 1; j /= 2) {
			if (num / j == 1) {
				cout << 1;
				num -= j;
				start = true;
			}
			else {
				if (start) {
					cout << '0';
				}
			}
		}
	}
	if (!start) {	// 입력이 0인 경우
		cout << 0;
	}
	return 0;
}