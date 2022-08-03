#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	if (k > n * n / 4) {
		cout << -1;
		return 0;
	}
	int a = n / 2, b = n - a;
	vector<int> cnt(b + 1);
	for (int i = 0; i < a; i++) {
		int x = min(b, k);
		cnt[b - x]++;
		k -= x;
	}
	for (int i = 0; i < b + 1; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			cout << 'A';
		}
		if (i < b) {
			cout << 'B';
		}
	}
	return 0;
}