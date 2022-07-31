#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;

// <초기 구현 버전>
// 아이디어 : 한 줄을 H로 만들고 나머지를 비교
// '과연 한 줄을 모두 H로 만든 경우가 최선인가?'에 대한 증명 불가능

// 실제로 구현 결과도 정답이 몇 개씩 늘어난 채로 출력됨
// 가령, 답이 37이라 하면 43과 같이.

void flip(vector<vector<bool>>& a, bool row, int x) {
	if (row) {
		for (int i = 0; i < n; i++) {
			a[x][i] = !a[x][i];
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			a[i][x] = !a[i][x];
		}
	}
}

int go(vector<vector<bool>> a, bool row, int x) {
	if (row) {
		for (int i = 0; i < n; i++) {
			if (a[x][i]) {
				flip(a, false, i);
			}
		}
		for (int i = 0; i < n; i++) {
			if (i == x) {
				continue;
			}
			int cnt = 0;	// t의 개수
			for (int j = 0; j < n; j++) {
				if (a[i][j]) {
					cnt++;
				}
			}
			if (cnt > n - cnt) {
				flip(a, true, i);
			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			if (a[i][x]) {
				flip(a, true, i);
			}
		}
		for (int i = 0; i < n; i++) {
			if (i == x) {
				continue;
			}
			int cnt = 0;	// t의 개수
			for (int j = 0; j < n; j++) {
				if (a[j][i]) {
					cnt++;
				}
			}
			if (cnt > n - cnt) {
				flip(a, false, i);
			}
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j]) {
				res++;
			}
		}
	}
	return res;
}

int main() {
	cin >> n;
	vector<vector<bool>> a(n, vector<bool>(n));
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			if (str[j] == 'T') {
				a[i][j] = true;
			}
		}
	}
	int ans = n * n;
	for (int i = 0; i < n; i++) {	// 모든 행
		ans = min(ans, go(a, true, i));
	}
	for (int i = 0; i < n; i++) {	// 모든 열
		ans = min(ans, go(a, false, i));
	}
	cout << ans;
}
