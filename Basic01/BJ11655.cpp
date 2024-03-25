#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	getline(cin, str);
	for (char ch : str) {
		if (ch >= 'a' && ch <= 'm'
			|| ch >= 'A' && ch <= 'M') {
			cout << static_cast<char>(ch + 13);
		}
		else if (ch >= 'n' && ch <= 'z') {
			cout << static_cast<char>('a' + ch % 'n');
		}
		else if (ch >= 'N' && ch <= 'Z') {
			cout << static_cast<char>('A' + ch % 'N');
		}
		else {
			cout << ch;
		}
	}
	return 0;
}