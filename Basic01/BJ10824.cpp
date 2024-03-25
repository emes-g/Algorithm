#include <iostream>
#include <string>
using namespace std;

// 자바와는 달리 long과 int의 범위가 같다.
// 자바의 long은 c++에서는 long long이다.

int main() {
	string num[4];
	for (int i = 0; i < 4; i++) {
		cin >> num[i];
	}
	num[0] += num[1];
	num[2] += num[3];
	cout << stoll(num[0]) + stoll(num[2]);
	return 0;
}