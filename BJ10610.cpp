#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a;
int sum;

// <30의 배수>
// → 2, 3, 5의 공배수
// 2, 5의 공배수 : 끝자리가 0이다.
// 3의 배수 : 모든 자릿수의 합이 3의 배수이다.

int main() {
	// 1. input
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		a.push_back(str[i] - '0');
		sum += a[i];
	}

	// 2. solve (greedy)
	sort(a.begin(), a.end(), greater<int>());
	if (sum % 3 != 0 || a.back() != 0) {	// 30의 배수가 아니라면
		cout << -1;
		return 0;
	}
	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
	}
}