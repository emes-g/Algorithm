#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string str;
	int n;
	cin >> str >> n;
	stack<char> left, right;
	
	// 초기 문자열
	for (char ch : str) {
		left.push(ch);
	}

	// 명령 수행
	while (n--) {
		char cmd;
		cin >> cmd;
		if (cmd == 'L') {
			if (left.size() != 0) {
				right.push(left.top());
				left.pop();
			}
		}
		else if (cmd == 'D') {
			if (right.size() != 0) {
				left.push(right.top());
				right.pop();
			}
		}
		else if (cmd == 'B') {
			if (left.size() != 0) {
				left.pop();
			}
		}
		else {
			char ch;
			cin >> ch;
			left.push(ch);
		}
	}

	// 출력
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}
	return 0;
}