#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1501;	// 최대 돌의 개수가 500개
bool check[MAX][MAX];
int sum;

// 인자 3개로 dfs를 실행하면 (1500)^3이 나와서 시공간적으로 불가능

void dfs(int a, int b) {
	check[a][b] = true;
	int g[3] = { a, b, sum - a - b };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (g[i] < g[j]) {
				a = g[i] * 2;
				b = g[j] - g[i];
				if (!check[a][b]) {
					dfs(a, b);
				}
			}
		}
	}
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	sum = a + b + c;
	if (sum % 3 != 0) {
		cout << 0;
		return 0;
	}
	dfs(a, b);
	cout << (check[sum / 3][sum / 3] ? 1 : 0);
}