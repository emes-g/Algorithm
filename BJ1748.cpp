#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// sum[n] : n자릿수까지 이어서 쓴 수의 자릿수
// ex) sum[2] : '1234...101112...9899'라는 수의 자릿수

// 시간복잡도 : O(상수)

int main() {
	int sum[9] = { 0 };
	for (int i = 1; i < 9; i++) {
		sum[i] = sum[i - 1] + 9 * pow(10, i - 1) * i;
	}

	int n, size, ans = 0;
	cin >> n;
	size = to_string(n).size();

	ans = sum[size - 1] + (n - pow(10, size - 1) + 1) * size;
	cout << ans;
	return 0;
}
