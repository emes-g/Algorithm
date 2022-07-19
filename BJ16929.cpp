#include <iostream>
#include <utility>
using namespace std;
char a[50][50];
bool check[50][50];
pair<int, int> k[4]{
	{0,1}, {1,0}, {0,-1}, {-1,0}
};

// <격자 형식의 사이클 찾기 문제>
// 기존 dfs의 cycle detection과는 확실한 차이가 있다.
// ex) 9466, 16724

bool dfs(pair<int, int> cur, pair<int, int> prev, int n, int m) {
	if (check[cur.first][cur.second]) {	// 
		return true;
	}
	check[cur.first][cur.second] = true;
	for (int i = 0; i < 4; i++) {
		int x = cur.first + k[i].first;
		int y = cur.second + k[i].second;
		if (x >= 0 && x < n && y >= 0 && y < m) {
			// 다음에 방문할 칸이 직전에 방문한 칸이 아니면서
			// 다음에 방문할 칸이 현재 칸과 색깔이 동일한 경우
			if (!(x == prev.first && y == prev.second) && a[x][y] == a[cur.first][cur.second]) {
				if (dfs({ x,y }, cur, n, m)) {
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			a[i][j] = str[j];
		}
	}

	// 2. solve (dfs)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!check[i][j]) {
				if (dfs({ i,j }, { -1,-1 }, n, m)) {
					cout << "Yes";
					return 0;
				}
			}
		}
	}
	cout << "No";
	return 0;
}