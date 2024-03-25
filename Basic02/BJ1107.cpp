#include <iostream>
#include <string>
using namespace std;
const int MAX = 1000000;
bool btn[10];

int detectFault(int x) {
	string temp = to_string(x);
	for (int j = 0; j < temp.size(); j++) {
		if (!btn[temp[j] - '0']) {	// char to int
			return -1;
		}
	}
	return temp.size();
}

int main() {
	// 1. input
	int n, m;
	cin >> n >> m;
	fill_n(btn, 10, true);
	while(m--){
		int num;
		cin >> num;
		btn[num] = false;
	}

	// 2. solve (brute force)
	int num[3] = { MAX, MAX, 100 };
	int size[3] = { 7, 7, 0 };
	for (int i = n; i <= MAX; i++) {
		int temp = detectFault(i);
		if (temp != -1) {
			num[0] = i;
			size[0] = temp;
			break;
		}
	}
	for (int i = n; i >= 0; i--) {
		int temp = detectFault(i);
		if (temp != -1) {
			num[1] = i;
			size[1] = temp;
			break;
		}
	}

	// 3. output
	int ans = MAX;
	for (int i = 0; i < 3; i++) {
		ans = min(ans, abs(num[i] - n) + size[i]);
	}
	cout << ans;
	return 0;
}
