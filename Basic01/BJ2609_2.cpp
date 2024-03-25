#include <iostream>
using namespace std;

int gcd(int x, int y) {	// x�� y�� ��Ұ���� ���ǹ�
	if (y == 0) {
		return x;
	}
	else {
		return gcd(y, x % y);
	}
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