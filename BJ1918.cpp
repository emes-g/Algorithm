#include <iostream>
#include <string>
#include <stack>
using namespace std;

int priority(char& ch) {
	if (ch == '(') {
		return 0;
	}
	else if (ch == '+' || ch == '-') {
		return 1;
	}
	else {
		return 2;
	}
}

int main() {
	string str;
	cin >> str;
	stack<char> op;
	for (char ch : str) {
		if (ch >= 'A' && ch <= 'Z') {
			cout << ch;
		}
		else if (ch == '(') {
			op.push(ch);
		}
		else if (ch == ')') {
			while (op.top() != '(') {
				cout << op.top();
				op.pop();
			}
			op.pop();
		}
		else {
			// top의 우선순위가 ch의 우선순위보다 높거나 같은 경우 출력하고 pop
			// 위를 만족하지 않거나 스택이 비어버리기 전까지 반복
			while (!op.empty() && priority(op.top()) >= priority(ch)) {
				cout << op.top();
				op.pop();
			}
			op.push(ch);
		}
	}
	while (!op.empty()) {
		cout << op.top();
		op.pop();
	}
	return 0;
}