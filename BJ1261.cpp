#include <iostream>
#include <queue>
using namespace std;
const int MAX = 10000;
int maze[100][100], a[100][100];
pair<int, int> k[4]{
	{0,1}, {1,0}, {0,-1}, {-1,0}
};

void bfs(int n, int m) {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	a[0][0] = 0;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {	// 상하좌우
			int f = k[i].first;
			int s = k[i].second;
			if (r + f >= 0 && r + f < n && c + s >= 0 && c + s < m) {
				if (a[r][c] + maze[r + f][c + s] < a[r + f][c + s]) {
					a[r + f][c + s] = a[r][c] + maze[r + f][c + s];
					q.push({ r + f,c + s });
				}
			}
		}
	}
}

int main() {
	// 1. input
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			maze[i][j] = str[j] - '0';
			a[i][j] = MAX;
		}
	}
	
	// 2. solve (bfs)
	bfs(n, m);

	// 3. output
	cout << a[n - 1][m - 1];
	return 0;
}