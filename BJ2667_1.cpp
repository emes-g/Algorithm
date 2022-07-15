#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[25][25], cnt = 0;
bool check[25][25];
pair<int, int> k[4]{
	{0, 1}, {1, 0}, {0, -1}, {-1, 0}
};
vector<int> ans;

void dfs(pair<int, int> node, int n) {
	check[node.first][node.second] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int x = node.first + k[i].first;
		int y = node.second + k[i].second;
		if (x >= 0 && x < n && y >= 0 && y < n) {
			if (a[x][y] == 1 && !check[x][y]) {
				dfs({ x, y }, n);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			a[i][j] = str[j] - '0';
		}
	}

	// 2. solve (dfs)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1 && !check[i][j]) {
				dfs({ i, j }, n);
				ans.push_back(cnt);
				cnt = 0;
			}
		}
	}

	// 3. output
	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (int i : ans) {
		cout << i << '\n';
	}
	return 0;
}