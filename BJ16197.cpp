#include <iostream>
#include <vector>
using namespace std;
char a[20][20];
int n, m;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<int> res;

// <개선의 여지가 있는 코드>
// 5108kb/68ms

void go(int level, int x1, int y1, int x2, int y2) {
	if ((x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) &&
		(x2 < 0 || x2 >= n || y2 < 0 || y2 >= m)) {
		// 둘 다 떨어진 상황
		return;
	}
	if ((x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) ||
		(x2 < 0 || x2 >= n || y2 < 0 || y2 >= m)) {
		// 하나만 떨어진 상황
		res.push_back(level);
		return;
	}
	if (level == 11) {
		// 10번보다 많이 이동한 상황
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		if (a[x1 + dx[i]][y1 + dy[i]] == '#') {
			if (a[x2 + dx[i]][y2 + dy[i]] == '#') {
				go(level + 1, x1, y1, x2, y2);
			}
			else {
				go(level + 1, x1, y1, x2 + dx[i], y2 + dy[i]);
			}
		}
		else {
			if (a[x2 + dx[i]][y2 + dy[i]] == '#') {
				go(level + 1, x1 + dx[i], y1 + dy[i], x2, y2);
			}
			else {
				go(level + 1, x1 + dx[i], y1 + dy[i], x2 + dx[i], y2 + dy[i]);
			}
		}
	}
}

int main() {
	// 1. input
	cin >> n >> m;
	int x1 = -1, x2 = -1, y1 = -1, y2 = -1;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			if (str[j] == 'o') {
				if (x1 != -1) {
					x2 = i;
					y2 = j;
				}
				else {
					x1 = i;
					y1 = j;
				}
			}
			a[i][j] = str[j];
		}
	}

	// 2. solve (brute force)
	go(0, x1, y1, x2, y2);

	// 3. output
	int ans = 11;
	for (auto it = res.begin(); it < res.end(); it++) {
		ans = min(ans, *it);
	}
	cout << (ans == 11 ? -1 : ans);
}