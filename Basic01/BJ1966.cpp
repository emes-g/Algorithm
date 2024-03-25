#include <iostream>
#include <queue>
using namespace std;
int n, m, a[100];

bool good(queue<int>& q, int x) {	// 현재 문서보다 중요도가 높은 문서가 뒤에 있는지 확인
	for (int i = 0; i < n; i++) {
		if (a[x] != -1 && a[x] < a[i]) {
			q.push(x);
			return false;
		}
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		queue<int> q;
		for (int i = 0; i < n; i++) {
			q.push(i);
		}

		int cnt = 1;	// 인쇄한 문서의 수
		while (true) {
			int x = q.front();
			q.pop();
			if (good(q, x)) {	// 현재 문서가 가장 중요도가 높은 경우
				if (x == m) {
					cout << cnt << '\n';
					break;
				}
				else {
					a[x] = -1;
					cnt++;
				}
			}
		}
	}
}