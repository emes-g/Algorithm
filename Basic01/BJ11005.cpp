#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n, b;
	cin >> n >> b;
	stack<int> s;
	while (n != 0) {
		s.push(n % b);
		n /= b;
	}
	while (!s.empty()) {
		if (s.top() >= 10) {
			cout << static_cast<char>('A' - 10 + s.top());
		}
		else {
			cout << s.top();
		}
		s.pop();
	}
	return 0;
}