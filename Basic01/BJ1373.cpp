#include <iostream>
#include <string>
using namespace std;

int main() {
	string bin;
	cin >> bin;
	size_t size = bin.size();
	if (size % 3 == 2) {
		cout << 2 * (bin[0] - '0') + 1 * (bin[1] - '0');
	}
	else if (size % 3 == 1) {
		cout << 1 * (bin[0] - '0');
	}
	for (size_t i = size % 3; i < size; i += 3) {	// mod 연산으로 초기화함으로써 원하는 위치에서 시작
		cout << 4 * (bin[i] - '0') + 2 * (bin[i + 1] - '0') + 1 * (bin[i + 2] - '0');
	}
	return 0;
}
