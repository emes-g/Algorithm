#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
vector<pii> home, store;

// <알고리즘>
// 1. 폐업시키지 않을 치킨집을 M개 이하로 고른다. (선택)
// 2. 도시의 치킨 거리 값을 최소로 갱신한다.
// 3. 1과 2를 반복한다.

int dist(pii x, pii y) {
	return abs(x.first - y.first) + abs(x.second - y.second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n, m, num = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			if (x == 1) {
				home.push_back({ i,j });
			}
			else if (x == 2) {
				store.push_back({ i,j });
				num++;
			}
		}
	}

	// 2. solve (bitmask)
	int ans = 1e4;
	for (int s = 0; s < (1 << num); s++) {
		int cnt = 0;
		vector<pii> running;	// 폐업시키지 않은 치킨집
		for (int i = 0; i < num; i++) {
			if (s & (1 << i)) {
				cnt++;
				running.push_back(store[i]);
			}
		}
		if (cnt > m) {
			continue;
		}

		int sum = 0;
		for (int i = 0; i < home.size(); i++) {
			int d = 1e2;
			for (int j = 0; j < running.size(); j++) {
				d = min(d, dist(home[i], running[j]));
			}
			sum += d;
		}
		ans = min(ans, sum);
	}
	cout << ans;
}