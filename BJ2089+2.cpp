#include <iostream>
#include <stack>
using namespace std;

// 애초에 불가능한 경우는 고려하지 않았다.
// ex) -13 2 (음수는 양의 진법으로 표현할 수 없다)

int main() {
	int n, k;
	cin >> n >> k;
	stack<int> s;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	while (n != 0) {
		// k > 0 -> n >= 0이므로 
		// 양의 진수같은 경우, 해당 조건을 만족할 일이 없다.
		if (n < 0 && n % k != 0) {
			s.push(n % k + abs(k));
			n = (n - abs(k)) / k;
		}
		else {
			s.push(n % k);
			n /= k;
		}
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	return 0;
}