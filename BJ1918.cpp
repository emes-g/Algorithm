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
			// top�� �켱������ ch�� �켱�������� ���ų� ���� ��� ����ϰ� pop
			// ���� �������� �ʰų� ������ �������� ������ �ݺ�
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