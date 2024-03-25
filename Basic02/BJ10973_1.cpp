#include <iostream>
using namespace std;
int a[10000];

bool prev_permutation(int n) {
	for (int i = n - 1; i >= 1; i--) {
		if (a[i - 1] > a[i]) {
			int j = i;
			while (j < n && a[i - 1] >= a[j]) {
				j++;
			}
			swap(a[i - 1], a[j - 1]);
			j = n - 1;
			while (i < j) {
				swap(a[i++], a[j--]);
			}
			return true;
		}
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (prev_permutation(n)) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
	}
	else {
		cout << -1;
	}
	return 0;
}