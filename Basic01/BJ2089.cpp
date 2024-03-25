#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	stack<int> s;

	while (n != 0) {
		if (n < 0 && n % -2 != 0) {	// 나머지가 음수인 경우
			s.push(n % -2 + 2);
			n = (n - 2) / -2;
		}
		else {
			s.push(n % -2);
			n /= -2;
		}
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	return 0;
}
