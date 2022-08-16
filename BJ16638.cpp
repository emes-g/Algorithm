#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// <문제 파악>
// 1. 우선순위 : 괄호 > 곱하기 > 그 외
// 2. 괄호는 중첩하지 않는다.

// <알고리즘>
// 1. 중첩되지 않은 괄호에 대하여, 괄호를 먼저 계산해준다.
// 2. 그 후, 우선순위에 따라 곱하기를 계산해준다.
// 3. 그 후, 앞에서부터 차례대로 연산을 수행한다.
// 4. 연산의 최댓값을 답으로 제출한다.

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
		// 1. 중첩된 괄호 존재 여부 확인
		bool good = true;
		for (int j = 0; j < m - 1; j++) {
			if ((i & (1 << j)) && (i & (1 << (j + 1)))) {
				good = false;
				break;
			}
		}
		if (!good) {
			continue;
		}

		// 2. 괄호 계산 (우선 순위가 존재하여 기존처럼 단순히 +와 0으로만 치환할 수 없다.)
		vector<int> num2;
		vector<char> op2;
		num2.push_back(num.front());
		for (int j = m - 1; j >= 0; j--) {
			int idx = (m - 1) - j;
			if (i & (1 << j)) {
				int temp = calc(num2.back(), num[idx + 1], op[idx]);
				num2.pop_back();
				num2.push_back(temp);
			}
			else {
				num2.push_back(num[idx + 1]);
				op2.push_back(op[idx]);
			}
		}
		

		// 3. 곱하기 계산
		vector<int> num3;
		vector<char> op3;
		num3.push_back(num2.front());
		for (int j = 0; j < op2.size(); j++) {
			if (op2[j] == '*') {
				int temp = calc(num3.back(), num2[j + 1], op2[j]);
				num3.pop_back();
				num3.push_back(temp);
			}
			else {
				num3.push_back(num2[j + 1]);
				op3.push_back(op2[j]);
			}
		}

		// 4. 차례대로 계산
		int res = num3.front();
		for (int j = 0; j < op3.size(); j++) {
			res = calc(res, num3[j + 1], op3[j]);
		}
		ans = max(ans, res);
	}
	cout << ans;
}