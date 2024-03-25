#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1501;	// 최대 돌의 개수가 500개
bool check[MAX][MAX];
int sum;

// <알고리즘>
// 1. 크기가 다른 2개를 고른다. (순서를 포함할 경우 3!)
// 2. 큰 그룹에서 작은 그룹의 크기만큼 돌을 빼서 작은 그룹에 추가한다.

// 인자 3개로 go를 실행하면 (1500)^3이 나와서 시공간적으로 불가능

void go(int a, int b) {
	check[a][b] = true;
	int g[3] = { a, b, sum - a - b };
	for (int i = 0; i < 3; i++) {	// 6가지 (자기 자신과 비교하는 경우 제외)
		for (int j = 0; j < 3; j++) {
			if (g[i] < g[j]) {
				a = g[i] * 2;
				b = g[j] - g[i];
				if (!check[a][b]) {
					go(a, b);
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
	go(a, b);
	cout << (check[sum / 3][sum / 3] ? 1 : 0);
}
