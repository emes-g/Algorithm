#include <iostream>
#include <vector>
#include <utility>
using namespace std;
vector<pair<int, int>> make_part();

// pair<int, int>[19] part
// 공통되지 않은 부분의 인덱스를 가리킨다.
// 해당 부분이 중심 블록에서 얼마만큼 떨어져 있는지를 나타낸다.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n + 4, vector<int>(m + 4, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	// 2. solve (brute force)
	int ans = 0;
	vector<pair<int, int>> part = make_part();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int sum = a[i][j] + a[i][j + 1] + a[i][j + 2];
			for (int k = 0; k < 19; k++) {
				if (k == 7) {
					sum = a[i][j] + a[i + 1][j] + a[i + 2][j];
				}
				else if (k == 14) {
					sum = a[i][j] + a[i][j + 1] + a[i + 1][j];
				}
				else if (k == 17) {
					sum = a[i][j] + a[i + 1][j] + a[i + 1][j + 1];
				}
				ans = max(ans, sum + a[i + part[k].first][j + part[k].second]);
			}
		}
	}

	// 3. output
	cout << ans << '\n';
	return 0;
}

vector<pair<int, int>> make_part() {
	vector<pair<int, int>> part(19);
	// 1. 가로로 3개
	part[0] = make_pair(0, 3);
	part[1] = make_pair(1, 0);
	part[2] = make_pair(-1, 2);
	part[3] = make_pair(-1, 0);
	part[4] = make_pair(1, 2);
	part[5] = make_pair(1, 1);
	part[6] = make_pair(-1, 1);

	// 2. 세로로 3개
	part[7] = make_pair(3, 0);
	part[8] = make_pair(2, 1);
	part[9] = make_pair(2, -1);
	part[10] = make_pair(0, 1);
	part[11] = make_pair(0, -1);
	part[12] = make_pair(1, 1);
	part[13] = make_pair(1, -1);

	// 3. 'ㄱ'을 y축에 대칭
	part[14] = make_pair(1, 1);
	part[15] = make_pair(1, -1);
	part[16] = make_pair(-1, 1);

	// 4. 'ㄴ'
	part[17] = make_pair(2, 1);
	part[18] = make_pair(0, -1);
	return part;
}