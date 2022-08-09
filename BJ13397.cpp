#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> a;

// <문제 분석>
// 최댓값의 최솟값 or 최솟값의 최댓값을 구하는 문제
// → '이분 탐색' 문제임을 생각해보기
 
// 결정 문제 : 구간의 점수의 최댓값이 mid여도 되는가?

// <변수 설명>
// cnt		구간의 점수의 최댓값을 mid라고 할 때, 지금까지 존재하는 그룹의 개수
// low		현재 그룹에서 최솟값
// high		현재 그룹에서 최댓값

bool good(int mid) {
	int cnt = 1, low = a[0], high = a[0];
	for (int i = 1; i < n; i++) {
		if (abs(a[i] - low) > mid || abs(a[i] - high) > mid) {	// 새로운 수를 포함했을 때 구간의 점수가 mid보다 커지는 경우
			cnt++;
			low = high = a[i];
		}
		else {
			low = min(low, a[i]);
			high = max(high, a[i]);
		}
	}
	return cnt <= m;
}

int binary_search(int left, int right) {
	while (left <= right) {
		int mid = (left + right) / 2;
		if (good(mid)) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	cin >> n >> m;
	a.resize(n);
	int low = 10000, high = 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		low = min(low, a[i]);
		high = max(high, a[i]);
	}

	// 2. solve (binary_search)
	cout << binary_search(0, high - low);
}