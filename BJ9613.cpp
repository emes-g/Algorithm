#include <iostream>
#include <string>
#include <vector>
using namespace std;

int gcd(int x, int y) {
	if (x < y) {	// 항상 x는 y보다 우위에 있다.
		int temp = x;
		x = y;
		y = temp;
	}

	int mod = x % y;
	while (mod != 0) {
		x = y;
		y = mod;
		mod = x % y;
	}
	return y;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> num(n);
		long long sum = 0;	// n이 100이고 100개의 수 전부 100만이라고 생각하면, sum이 49.5억이 나오므로 int로는 불가능하다. 
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}

		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				sum += gcd(num[i], num[j]);
			}
		}
		cout << sum << '\n';
	}
	return 0;
}