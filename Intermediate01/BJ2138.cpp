#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<bool> a, b;

// i번 스위치로 (i-1)번 전구를 변경한다.
// 이 때, 1번 스위치와 n번 전구는 별도로 생각해주어야 한다.

void input() {
	string str;
	cin >> str;
	for (int i = 0; i < n; i++) {
		if (str[i] - '0') {
			a[i] = true;
		}
	}
	cin >> str;
	for (int i = 0; i < n; i++) {
		if (str[i] - '0') {
			b[i] = true;
		}
	}
}

int go(bool first) {
	int cnt = 0;
	vector<bool> temp(n);
	for (int i = 0; i < n; i++) {
		temp[i] = a[i];
	}

	if (first) {	// 0번 스위치를 누른 경우
		cnt++;
		temp[0] = !temp[0];
		temp[1] = !temp[1];
	}
	for (int i = 1; i < n - 1; i++) {	// 1번~(n-2)번 스위치
		if (temp[i - 1] != b[i - 1]) {
			cnt++;
			temp[i - 1] = !temp[i - 1];
			temp[i] = !temp[i];
			temp[i + 1] = !temp[i + 1];
		}
	}
	if (temp[n - 2] != b[n - 2]) {	// (n-1)번 스위치
		cnt++;
		temp[n - 2] = !temp[n - 2];
		temp[n - 1] = !temp[n - 1];
	}
	
	// 위 과정을 거치면 마지막 전구를 제외한 모든 전구는 동일한 상태가 될 수 밖에 없음
	if (temp[n - 1] != b[n - 1]) {
		return -1;
	}
	else {
		return cnt;
	}
}

int main() {
	// 1. input
	cin >> n;
	a.assign(n, false);
	b.assign(n, false);
	input();
	
	// 2. solve (greedy)
	int first[2] = { go(true), go(false) };
	if (first[0] == -1 && first[1] == -1) {
		cout << -1;
	}
	else {
		if (first[0] != -1 && first[1] != -1) {
			cout << min(first[0], first[1]);
		}
		else {
			cout << max(first[0], first[1]);
		}
	}
}
