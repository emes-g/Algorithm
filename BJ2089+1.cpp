#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	stack<int> s;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	while (n != 0) {
		if (n < 0 && n % -4 != 0) {
			s.push(n % -4 + 4);
			n = (n - 4) / -4;
		}
		else {
			s.push(n % -4);
			n /= -4;
		}
	}
	
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	return 0;
}