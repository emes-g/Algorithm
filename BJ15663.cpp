#include <iostream>
#include <algorithm>
using namespace std;
bool check[8];
int num[8], input[8];

// 기존 풀이는 대부분 맞지만 반례와 같은 특정 상황을 잡지 못한다.
// 왜? num[level]에 있는 수가 항상 input[i]와 비교되면 안 된다.
// 특정 레벨의 BT이 끝난 이후, 해당 레벨의 BT이 다시 호출되었을 때는 num[level]을 고려해서는 안 된다.

// 그러면 어떻게 해?
// BT의 지역변수로써 num[level]의 기능을 할 수 있는 변수 prev를 생성한다.
// 기능은 num[level]과 동일하지만 BT이 종료되면 지역변수이기 때문에 사라진다.

// 만약 prev가 전역변수라면?
// 기존의 문제가 해결되지 않을 뿐더러, 추가적인 문제가 발생할 수 있다.

void BT(int level, int n, int m) {
	if (level == m) {
		for (int i = 0; i < m; i++) {
			cout << num[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int prev = 0;
	for (int i = 0; i < n; i++) {
		if (!check[i] && prev != input[i]) {
			check[i] = true;
			prev = num[level] = input[i];
			BT(level + 1, n, m);
			check[i] = false;
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	sort(input, input + n);
	BT(0, n, m);
	return 0;
}
