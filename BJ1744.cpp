#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
priority_queue<int> pos;
priority_queue<int, vector<int>, greater<int>> neg;
bool zero;

// 1. 양수는 내림차순, 음수는 오름차순으로 정렬한다.
// 2. 다음의 경우를 생각한다. 
// (O : 묶는다, X : 안 묶는다)
// - - : O
// - 0 : O
// - + : X
// 0 + : X
// + + : 곱이 더 크다면 O, 아니면 X

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num > 0) {
			pos.push(num);
		}
		else if (num < 0) {
			neg.push(num);
		}
		else {
			zero = true;
		}
	}

	int sum = 0;
	while (!neg.empty()) {
		if (neg.size() == 1) {
			if (!zero) {
				sum += neg.top();
			}
			break;
		}
		int x = neg.top();
		neg.pop();
		int y = neg.top();
		neg.pop();
		sum += x * y;
	}
	while (!pos.empty()) {
		if (pos.size() == 1) {
			sum += pos.top();
			break;
		}
		int x = pos.top();
		pos.pop();
		int y = pos.top();
		pos.pop();
		sum += max(x + y, x * y);
	}
	cout << sum;
}