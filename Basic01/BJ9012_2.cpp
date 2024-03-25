#include <iostream>
#include <string>
#include <stack>
using namespace std;

string valid(string& str) {
	int size = 0;
	for (char ch : str) {
		if (ch == '(') {
			size++;
		}
		else {
			if (size == 0) {
				return "NO";
			}
			else {
				size--;
			}
		}
	}
	if (size == 0) {
		return "YES";
	}
	else {
		return "NO";
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		string str;
		cin >> str;
		cout << valid(str) << '\n';
	}
	return 0;
}