#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000;
bool a[MAX][MAX], check[MAX][MAX];
int n, m, g[MAX][MAX];
vector<int> area;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

// 연결 요소 구성원 & 개수 파악하기
void dfs(int x, int y, int num) {
	check[x][y] = true;
	g[x][y] = num;
	area[num]++;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (!a[nx][ny] && !check[nx][ny]) {
				dfs(nx, ny, num);
			}
		}
	}
}

// 상하좌우 확인
int go(int x, int y, vector<bool> area_visit) {
	int cnt = 1;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if (!a[nx][ny]) {
				if (!area_visit[g[nx][ny]]) {	// 방문한 연결 요소가 아니라면 해당 연결 요소의 크기만큼 추가
					cnt += area[g[nx][ny]];
					area_visit[g[nx][ny]] = true;
				}
			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			if (str[j] - '0') {
				a[i][j] = true;
			}
		}
	}

	// 2. solve (dfs & go)
	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!a[i][j] && !check[i][j]) {
				area.push_back(0);
				dfs(i, j, num++);
			}
		}
	}

	vector<bool> area_visit(num, false);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j]) {
				cout << go(i, j, area_visit) % 10;
			}
			else {
				cout << 0;
			}
		}
		cout << '\n';
	}
}
