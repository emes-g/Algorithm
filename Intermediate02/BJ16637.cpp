#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// <문제 파악>
// 해당 연산자를 묶을지 말지 선택해야 한다.
// 연산자가 최대 9개이므로 비트마스크로 구현해도 무방하다.
// 단, 연산자가 연속으로 묶이면 안 된다!

int calc(int x, int y, char ch) {
	switch (ch) {
	case '+':
		return x + y;
	case '-':
		return x - y;
	case '*':
		return x * y;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// 1. input
	int n, m, ans = INT_MIN;
	string str;
	cin >> n >> str;
	m = n / 2;	// 연산자 개수
	n -= m;		// 숫자 개수
	vector<int> num;
	vector<char> op;
	for (int i = 0; i < str.size(); i++) {
		if (i % 2 == 0) {
			num.push_back(str[i] - '0');
		}
		else {
			op.push_back(str[i]);
		}
	}

	// 2. solve (bitmask)
	for (int i = 0; i < (1 << m); i++) {
		bool good = true;
		for (int j = 0; j < m - 1; j++) {	// 괄호가 중첩된 경우 (제외)
			if ((i & (1 << j)) && (i & (1 << (j + 1)))) {
				good = false;
				break;
			}
		}
		if (!good) {
			continue;
		}

		vector<int> num2(num);	// deep copy
		vector<char> op2(op);
		for (int j = 0; j < m; j++) {
			if (i & (1 << j)) {
				int idx = (m - 1) - j;
				num2[idx] = calc(num2[idx], num2[idx + 1], op2[idx]);
				num2[idx + 1] = 0;
				op2[idx] = '+';
			}
		}

		int res = num2[0];
		for (int i = 0; i < m; i++) {
			res = calc(res, num2[i + 1], op2[i]);
		}
		ans = max(ans, res);
	}
	cout << ans;
}