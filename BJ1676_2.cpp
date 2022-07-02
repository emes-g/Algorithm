#include <iostream>
using namespace std;

int solve(int n, int num) {
	// n이 자료형의 최대치에 근접하게 큰 수라면, 오버플로우 발생할 수 있다.
	long long div = num;
	int cnt = 0;
	while (n / div != 0) {
		cnt += n / div;
		div *= num;
	}
	return cnt;
}

int main() {
	int n;
	cin >> n;
	cout << solve(n, 5);
	return 0;
}
