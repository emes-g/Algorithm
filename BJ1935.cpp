#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int n;
	string str;
	cin >> n >> str;

	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}

	stack<double> s;
	for (char ch : str) {
		if (ch == '+' || ch == '-' ||
			ch == '*' || ch == '/') {
			double x = s.top();
			s.pop();
			double y = s.top();
			s.pop();
			switch (ch) {
			case '+':
				s.push(y + x);
				break;
			case '-':
				s.push(y - x);
				break;
			case '*':
				s.push(y * x);
				break;
			case '/':
				s.push(y / x);
				break;
			}
		}
		else {
			s.push(num[static_cast<int>(ch - 'A')]);
		}
	}
	printf("%.2f", s.top());
}