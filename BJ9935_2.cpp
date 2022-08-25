#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int n, m;

// <문제 파악>
// string을 stack처럼 사용하는 방법

bool good(string& ans, string& exp) {
	int last = ans.size() - 1;
	for (int i = 1; i < m; i++) {
		if (last - i >= 0 && (ans[last - i] != exp[m - 1 - i])) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// 1. input
	string str, exp, ans;
	cin >> str >> exp;
	n = str.size();
	m = exp.size();

	// 2. solve (string)
	for (int i = 0; i < n; i++) {
		ans += str[i];
		if (ans.size() >= m && ans.back() == exp[m - 1]) {
			if (good(ans, exp)) {
				for (int j = 0; j < m; j++) {
					ans.pop_back();
				}
			}
		}
	}
	cout << (ans == "" ? "FRULA" : ans);
}