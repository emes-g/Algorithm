#include <iostream>
#include <string>
using namespace std;

// �ڹٿʹ� �޸� long�� int�� ������ ����.
// �ڹ��� long�� c++������ long long�̴�.

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