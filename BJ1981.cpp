#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
bool check[100][100];
int n, a[100][100];
int MIN, MAX;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

// <문제 분석>
// binary_search + dfs/bfs + brute force
// n이 상당히 작아서 bfs하는 모든 경우를 brute force로 해결해 볼 수 있다.

// 결정 문제 : (최대 - 최소)의 값이 mid여도 되는가?
// 시간 복잡도 : O(log(MAX - MIN)) * O(MAX - MIN) * O(bfs 1회)
// → O(binary search) * O(brute force) * O(bfs 1회)

bool bfs(int gap) {
	for (int i = MIN; i + gap <= MAX; i++) {
		if (a[0][0] < i || a[0][0] > i + gap) {
			continue;
		}
		memset(check, false, sizeof(check));
		queue<pair<int, int>> q;
		q.push({ 0,0 });
		check[0][0] = true;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (x == n - 1 && y == n - 1) {
				return true;
			}
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
					int next = a[nx][ny];
					if (!check[nx][ny] && (i <= next && next <= i + gap)) {
						q.push({ nx,ny });
						check[nx][ny] = true;
					}
				}
			}
		}
	}
	return false;
}

bool good(int mid) {
	return bfs(mid);
}

int binary_search(int left, int right) {
	while (left <= right) {
		int mid = (left + right) / 2;
		if (good(mid)) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	cin >> n;
	MIN = 200, MAX = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			MIN = min(MIN, a[i][j]);
			MAX = max(MAX, a[i][j]);
		}
	}

	// 2. solve (binary_search)
	cout << binary_search(0, MAX - MIN);
}