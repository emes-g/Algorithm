#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

// <문제 파악>
// 뒤에서부터 날짜를 셌을 때, (5일, 4일, 3일, ...)
// 현재 날짜에서 풀 수 있는 문제들 중 컵라면을 가장 많이 주는 문제를 해결
// → 그리디 (활동 선택)

// 순회 강연(2109)과 동일한 문제

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n;
	cin >> n;
	vector<pii> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end(), greater<pii>());	// 데드라인을 내림차순으로

	// 2. solve (greedy)
	priority_queue<int> pq;
	int idx = 0, ans = 0;
	for (int i = n; i > 0; i--) {
		while (idx < n && a[idx].first == i) {
			pq.push(a[idx++].second);
		}

		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
}