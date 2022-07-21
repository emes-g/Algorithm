#include <iostream>
#include <algorithm>
using namespace std;
int a[8], num[8];
bool check[8];

// input
// 3 3
// 1 1 2

// output
// 1 1 2
// 1 2 1
// 2 1 1

// 기존 풀이는 대부분 맞지만 반례와 같은 특정 상황을 잡지 못한다.
// 왜? a[level]에 있는 수가 항상 num[i]와 비교되면 안 된다.
// 특정 레벨의 go가 끝난 이후, 해당 레벨의 go가 다시 호출되었을 때는 a[level]을 고려해서는 안 된다.

// 그러면 어떻게 해?
// go의 지역변수로써 a[level]의 기능을 할 수 있는 변수 prev를 생성한다.
// 기능은 a[level]과 동일하지만 go가 종료되면 지역변수이기 때문에 사라진다.

// 만약 prev가 전역변수라면?
// 기존의 문제가 해결되지 않을 뿐더러, 추가적인 문제가 발생할 수 있다.

void go(int level, int n, int m) {
	if (level == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int prev = 0;
	for (int i = 0; i < n; i++) {
		if (!check[i] && prev != num[i]) {
			check[i] = true;
			prev = a[level] = num[i];
			go(level + 1, n, m);
			check[i] = false;
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);
	go(0, n, m);
}
