#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int> t;
vector<t> groups;
int n, m, k, ans = 5000;

// <주요 함수>
// algorithm::rotate(iterator start, iterator end, iterator point)
// 구간 [start, end)에 속하는 원소들을 point 위치로 보낸다.

// <문제 파악>
// rotate를 활용한 브루트 포스
// 시간 복잡도 : K! * O(해당 순열에서의 연산)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	cin >> n >> m >> k;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		groups.push_back({ r - 1,c - 1,s });
	}
	sort(groups.begin(), groups.end());

	// 2. solve (permutation)
	do {
		vector<vector<int>> temp(a);
		for (t g : groups) {
			int r, c, s;
			tie(r, c, s) = g;
			for (int l = 1; l <= s; l++) {
				vector<int> val;
				for (int i = r - l, j = c - l; j < c + l; j++) {
					val.push_back(temp[i][j]);
				}
				for (int i = r - l, j = c + l; i < r + l; i++) {
					val.push_back(temp[i][j]);
				}
				for (int i = r + l, j = c + l; j > c - l; j--) {
					val.push_back(temp[i][j]);
				}
				for (int i = r + l, j = c - l; i > r - l; i--) {
					val.push_back(temp[i][j]);
				}
				rotate(val.begin(), val.end() - 1, val.end());

				int idx = 0;
				for (int i = r - l, j = c - l; j < c + l; j++) {
					temp[i][j] = val[idx++];
				}
				for (int i = r - l, j = c + l; i < r + l; i++) {
					temp[i][j] = val[idx++];
				}
				for (int i = r + l, j = c + l; j > c - l; j--) {
					temp[i][j] = val[idx++];
				}
				for (int i = r + l, j = c - l; i > r - l; i--) {
					temp[i][j] = val[idx++];
				}
			}
		}
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < m; j++) {
				sum += temp[i][j];
			}
			ans = min(ans, sum);
		}
	} while (next_permutation(groups.begin(), groups.end()));
	cout << ans;
}