#include <iostream>
#include <utility>
#include <queue>
using namespace std;
int dis[300][300];
bool check[300][300];
pair<int, int> k[8]{
	{-2,1}, {-1,2}, {1,2}, {2,1}, 
	{2,-1}, {1,-2}, {-1,-2}, {-2,-1}
};

void bfs(pair<int, int> start, int l) {
	queue<pair<int, int>> q;
	q.push(start);
	while (!q.empty()) {
		auto node = q.front();
		q.pop();
		check[node.first][node.second] = true;
		for (int i = 0; i < 8; i++) {
			int x = node.first + k[i].first;
			int y = node.second + k[i].second;
			if (x >= 0 && x < l && y >= 0 && y < l) {
				if (!check[x][y]) {
					q.push({ x,y });
					dis[x][y] = dis[node.first][node.second] + 1;
					check[x][y] = true;
				}
			}
		}
	}
}

void init(int l) {
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			dis[i][j] = 0;
			check[i][j] = false;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int l;
		cin >> l;
		pair<int, int> start, goal;
		cin >> start.first >> start.second >> goal.first >> goal.second;
		bfs(start, l);
		cout << dis[goal.first][goal.second] << '\n';
		init(l);
	}
	return 0;
}