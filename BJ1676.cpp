#include <iostream>
using namespace std;

int five(int n) {
	return n / 5 + n / 25 + n / 125;
}

int main() {
	int n;
	cin >> n;
	cout << five(n);
	return 0;
}