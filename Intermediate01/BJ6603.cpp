#include <iostream>
#include <vector>
using namespace std;
vector<int> s;
int a[6];

void go(int level, int index, int k) {
	if (level == 6) {
		for (int i = 0; i < 6; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}
	else if (index >= k) {
		return;
	}
	a[level] = s[index];
	go(level + 1, index + 1, k);
	go(level, index + 1, k);
}

int main() {
	while (true) {
		int k;
		cin >> k;
		if (k == 0) {
			return 0;
		}
		s.assign(k, 0);
		for (int i = 0; i < k; i++) {
			cin >> s[i];
		}
		go(0, 0, k);
		cout << '\n';
	}
}