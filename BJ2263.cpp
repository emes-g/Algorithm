#include <iostream>
using namespace std;
const int MAX = 100000;
int in[MAX], post[MAX], pos[MAX + 1];

// <분할 정복>
// 큰 하나의 경우를 해결하면,
// 작은 하나의 경우도 그 방법대로 해결할 수 있다!

// <문제 핵심>
// 1. 포스트오더의 마지막 숫자가 root이다.
// 2. 인오더는 root를 기준으로 서브트리가 나누어진다.

// <알고리즘>
// 1. 포스트오더의 마지막 숫자를 통해 root를 파악한다.
// 2. 인오더에서의 루트의 위치를 p에 저장한다.
// 3. 프리오더이므로 자기 자신 출력
// 4. 프리오더이므로 왼쪽 서브트리 우선 진행, 이후 오른쪽 서브트리 진행

void go(int s1, int e1, int s2, int e2) {
	if (s1 > e1 || s2 > e2) {
		return;
	}
	int root = post[e2];
	int p = pos[root];
	
	cout << root << ' ';
	int l = p - s1;	// 왼쪽 서브 트리의 노드의 개수 → 포스트오더의 범위를 지정할 수 있음
	go(s1, p - 1, s2, s2 + l - 1);
	go(p + 1, e1, s2 + l, e2 - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> post[i];
	}

	// 2. solve (dnc)
	for (int i = 0; i < n; i++) {
		pos[in[i]] = i;
	}
	go(0, n - 1, 0, n - 1);
}