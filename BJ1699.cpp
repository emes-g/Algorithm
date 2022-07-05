#include <iostream>
#include <cmath>
using namespace std;

// 반례 : 32
// 문제에서 원하는 답 : 16 + 16 (2)
// 아래 코드를 통해 구현된 답 : 25 + 4 + 1 + 1 + 1 (5)

int main() {
	int n, cnt = 0;
	cin >> n;

	for (int i = sqrt(n); n != 0; i--) {
		int temp = static_cast<int>(pow(i, 2));
		while (n - temp >= 0) {
			cnt++;
			n -= temp;
		}
	}
	
	cout << cnt;
	return 0;
}
