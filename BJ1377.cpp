#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// <포인트>
// Bubble Sort를 1회 진행하면 각 숫자는 최대 좌측으로 1칸 움직일 수 있다. ... ㄱ
// 정렬 전 인덱스 - 정렬 후 인덱스 
// → 좌측으로 이동한 횟수 (∵ ㄱ)
// → Bubble Sort의 진행 횟수

// 문제에서 제시된 코드를 보았을 때,
// Bubble Sort가 만일 2회 필요했다면
// i값이 3일때 change가 false인 채로 함수가 종료될 것이다.
// 그러므로, Bubble Sort의 진행 횟수 + 1이 정답이다.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, a[i].second - i);
	}
	cout << ans + 1;
}