#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// 현재 담을 수 있는 가방 중에서 가장 비싼 보석을 담아야 한다.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> a;	// 보석
	for (int i = 0; i < n; i++) {
		int m, v;
		cin >> m >> v;
		a.push_back({ m,v });
	}
	vector<int> c(k);	// 용량
	for (int i = 0; i < k; i++) {
		cin >> c[i];
	}

	// 2. sort (무게 순 정렬)
	sort(a.begin(), a.end(), [](auto x, auto y) {
		if (x.first == y.first) {
			return x.second < y.second;
		}
		else {
			return x.first < y.first;
		}
		});
	sort(c.begin(), c.end());	
	
	// 3. solve (greedy)
	priority_queue<int> pq;	// 현재 가방에 담을 수 있는 보석들을 저장한다.
	long long idx = 0, res = 0;
	for (int i = 0; i < k; i++) {
		while (idx < n && a[idx].first <= c[i]) {
			pq.push(a[idx++].second);
		}

		if (!pq.empty()) {	// pq에서 가장 비싼 보석을 담고 지운다.
			res += pq.top();
			pq.pop();
		}
	}
	cout << res;
}