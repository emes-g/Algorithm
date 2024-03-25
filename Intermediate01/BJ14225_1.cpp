#include <iostream>
using namespace std;
const int MAX = 2000001;
int a[20];
bool check[MAX];

int main() {
	// 1. input
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// 2. solve (bitmask)
	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				sum += a[j];
			}
		}
		if (!check[sum]) {
			check[sum] = true;
		}
	}

	// 3. output
	for (int i = 1; i < MAX; i++) {
		if (!check[i]) {
			cout << i;
			return 0;
		}
	}
}