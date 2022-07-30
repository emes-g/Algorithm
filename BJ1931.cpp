#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> a;

// 이전의 선택과 관련 없이 현재 상태에서 최선의 결과를 선택하여 최적의 결과를 낼 수 있다.
// → 그리디 알고리즘

bool cmp(pair<int, int> x, pair<int, int> y) {
	if (x.second != y.second) {
		return x.second < y.second;
	}
	else {	// 종료 시간이 같은 경우, 시작 시간이 빠른 것을 우선적으로 선택
		return x.first < y.first;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n;
	cin >> n;
	a.assign(n, { 0,0 });
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}

	// 2. solve (greedy)
	sort(a.begin(), a.end(), cmp);
	int ans = 1;
	auto m = a[0];
	for (auto it = a.begin() + 1; it < a.end(); it++) {
		if (m.second <= it->first) {
			ans++;
			m = *it;
		}
	}
	cout << ans;
}