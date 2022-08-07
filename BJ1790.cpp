#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int k, sum[10];

int digit(int n) {
	int size = to_string(n).size();
	int ret = sum[size - 1] + (n - pow(10, size - 1) + 1) * size;
	return ret;
}

bool good(int mid) {
	return digit(mid) < k;	// 부등호가 <=라면 right를 반환해야 함.
}

int binary_search(int left, int right) {
	int goal = 7;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (good(mid)) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return left;
}

int main() {
	// 1. input
	for (int i = 1; i < 9; i++) {
		sum[i] = sum[i - 1] + 9 * pow(10, i - 1) * i;
	}
	sum[9] = sum[8] + 9;
	int n;
	cin >> n >> k;
	if (digit(n) < k) {	// 수의 길이가 k보다 작은 경우
		cout << -1;
		return 0;
	}

	// 2. solve
	int res = binary_search(1, n);
	int start = digit(res - 1);
	int end = digit(res);
	string str = to_string(res);
	for (int i = start + 1; i <= end; i++) {
		if (i == k) {
			cout << str[i - start - 1];
			return 0;
		}
	}
}