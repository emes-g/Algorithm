#include <iostream>
using namespace std;

int gcd(int x, int y) {	// x와 y의 대소관계는 무의미
	int mod = x % y;
	while (mod != 0) {
		x = y;
		y = mod;
		mod = x % y;
	}
	return y;
}

int lcm(int x, int y) {
	return x * y / gcd(x, y);
}

int main() {
	int x, y;
	cin >> x >> y;
	cout << gcd(x, y) << '\n';
	cout << lcm(x, y) << '\n';
	return 0;
} 
