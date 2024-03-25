#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

// 가방 무게가 작은 것부터 시작하여,
// 현재 담을 수 있는 보석 중에서 가장 비싼 보석을 담아야 한다. (현재 시점에서 최적인 선택)
// → priority queue로 구현해야 한다.
// (pq의 기본 정렬 순서는 내림차순)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n, k;
	cin >> n >> k;
	vector<pii> a(n);	// 보석
	vector<int> g(k);	// 용량
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	for (int i = 0; i < k; i++) {
		cin >> g[i];
	}
	sort(a.begin(), a.end());
	sort(g.begin(), g.end());
	
	// 2. solve (greedy)
	priority_queue<int> pq;	// 현재 가방에 담을 수 있는 보석들
	long long idx = 0, ans = 0;
	for (int i = 0; i < k; i++) {
		while (idx < n && a[idx].first <= g[i]) {
			pq.push(a[idx++].second);
		}

		if (!pq.empty()) {	// 가장 비싼 보석을 담는다.
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
}
