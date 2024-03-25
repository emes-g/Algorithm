#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<char> s;
	string str;
	getline(cin, str);
	str += "\n";
	bool tag = false;
	for (char ch : str) {
		if (tag) {	// 태그가 열린 상황에서는 그대로 출력
			if (ch == '>') {
				tag = false;
				cout << '>';
			}
			else {
				cout << ch;
			}
		}
		else {	// 태그가 열리지 않은 상황에서는 거꾸로 출력
			if (ch == '<') {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				tag = true;
				cout << '<';
			}
			else if (ch == ' ' || ch == '\n') {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << ' ';
			}
			else {
				s.push(ch);
			}
		}
	}
	return 0;
}