#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

int main() {
	int a, b, m, dec = 0;
	cin >> a >> b >> m;
	for (int i = 0; i < m; i++) {	// a to 10
		int num;
		cin >> num;
		dec += pow(a, m - 1 - i) * num;
	}

	stack<int> s;
	while (dec != 0) {	// 10 to b
		s.push(dec % b);
		dec /= b;
	}
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
}