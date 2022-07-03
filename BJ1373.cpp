#include <iostream>
#include <string>
using namespace std;

int main() {
	string bin;
	cin >> bin;
	if (bin == "0") {
		cout << 0;
		return 0;
	}
	size_t i = 0, size = bin.size();
	if (size % 3 != 0) {
		if (size % 3 == 1) {
			cout << 1;
			i = 1;
		}
		else {
			if (bin[1] == '0') {
				cout << 2;
			}
			else {
				cout << 3;
			}
			i = 2;
		}
	}
	for (; i < size; i += 3) {
		int temp = (bin[i] == '1') ? 4 : 0;
		temp += (bin[i + 1] == '1') ? 2 : 0;
		temp += (bin[i + 2] == '1') ? 1 : 0;
		cout << temp;
	}
	return 0;
}