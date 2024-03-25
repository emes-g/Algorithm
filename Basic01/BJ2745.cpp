#include <iostream>
#include <string>
#include <cmath>	// for using pow
using namespace std;

int main() {
	string n;
	int b, sum = 0;
	cin >> n >> b;
	for (int i = 0; i < n.size(); i++) {
		int val = n[i] - '0';
		if (n[i] >= 'A' && n[i] <= 'Z') {
			val = n[i] - 'A' + 10;
		}
		sum += static_cast<int>(pow(b, n.size() - 1 - i)) * val;
	}
	cout << sum;
	return 0;
}