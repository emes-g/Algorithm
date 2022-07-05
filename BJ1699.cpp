#include <iostream>
#include <cmath>
using namespace std;

// 반례 : 27

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