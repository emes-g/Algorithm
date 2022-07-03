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
		if (n < 0 && abs(n % -2) == 1) {	// 나머지가 음수가 나오는 유일한 경우
			s.push(1);
			n -= 1;
		}
		else {
			s.push(n % -2);
		}
		n /= -2;
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	return 0;
}