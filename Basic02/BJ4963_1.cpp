#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[50][50], cnt = 0;
bool check[50][50];
pair<int, int> k[8]{
	{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}
};

void init(int h, int w) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			a[i][j] = 0;
			check[i][j] = false;
		}
	}
	cnt = 0;
}

void dfs(pair<int, int> node, int h, int w) {
	check[node.first][node.second] = true;
	for (int i = 0; i < 8; i++) {
		int x = node.first + k[i].first;
		int y = node.second + k[i].second;
		if (x >= 0 && x < h && y >= 0 && y < w) {
			if (a[x][y] == 1 && !check[x][y]) {
				dfs({ x, y }, h, w);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true) {
		// 1. input
		int h, w;
		cin >> w >> h;
		if (h == 0 && w == 0) {
			return 0;
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> a[i][j];
			}
		}

		// 2. solve (dfs)
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (a[i][j] == 1 && !check[i][j]) {
					dfs({ i, j }, h, w);
					cnt++;
				}
			}
		}

		// 3. output
		cout << cnt << '\n';
		init(h, w);
	}
}