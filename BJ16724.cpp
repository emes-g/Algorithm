#include <iostream>
using namespace std;
const int MAX = 1000;
char a[MAX][MAX];
bool check[MAX][MAX], finish[MAX][MAX];
int cycle;

// check[i] && !finish[i] <=> back edge <=> cycle detection

void dfs(int r, int c) {
	if (!check[r][c]) {
		check[r][c] = true;
		switch (a[r][c]) {
		case 'D':
			dfs(r + 1, c);
			break;
		case 'R':
			dfs(r, c + 1);
			break;
		case 'U':
			dfs(r - 1, c);
			break;
		case 'L':
			dfs(r, c - 1);
			break;
		}
		finish[r][c] = true;
	}
	else if (!finish[r][c]) {
		cycle++;
		return;
	}
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

	// 2. solve (dfs -> cycle detection)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!check[i][j]) {
				dfs(i, j);
			}
		}
	}

	// 3. output
	cout << cycle;
	return 0;
}