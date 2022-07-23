#include <iostream>
using namespace std;
const int MAX = 2000001;
int a[20];
bool check[MAX];

void go(int index, int sum, int n) {
	if (index == n) {
		check[sum] = true;
		return;
	}
	go(index + 1, sum + a[index], n);
	go(index + 1, sum, n);
}

int main() {
	// 1. input
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// 2. solve
	go(0, 0, n);

	// 3. output
	for (int i = 1; i < MAX; i++) {
		if (!check[i]) {
			cout << i;
			return 0;
		}
	}
}