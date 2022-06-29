#include <iostream>
#include <string>
#include <stack>
using namespace std;

string valid(string& str) {
	stack<char> s;
	for (char ch : str) {
		if (ch == '(') {
			s.push(ch);
		}
		else {
			if (s.empty()) {
				return "NO";
			}
			else {
				s.pop();
			}
		}
	}
	if (s.empty()) {
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