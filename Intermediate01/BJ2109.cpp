#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
const int MAX = 10001;

// 먼 날부터 시작하여, 할 수 있는 강연들 중 가장 pay가 높은 강연을 한다.

// 시간복잡도 : O(n)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end(), [](auto x, auto y) {
		if (x.second == y.second) {
			return x.first > y.first;
		}
		else {
			return x.second > y.second;
		}
		});

	priority_queue<int> pq;
	int idx = 0, ans = 0;
	for (int i = MAX; i > 0; i--) {
		while (idx < n && a[idx].second >= i) {
			pq.push(a[idx++].first);
		}

		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
}