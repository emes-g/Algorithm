#include <iostream>
#include <vector>
using namespace std;

// <문제 해설>
// B를 b개 먼저 배치해놓고,
// A가 앉을 자리를 선택하는 문제

// A가 a개 있고, B가 b개 있다고 하면
// 만들 수 있는 순서쌍의 range는 구간 [0, ab]

// 맨 앞에 배치할 수 있는 만큼 최대한 배치하고,
// 맨 앞에 배치할 수 없을 때 중간에 한 번 배치하고,
// 남은 a는 모두 맨 뒤에 배치한다.

int main() {
	// 1. input
	int n, k;
	cin >> n >> k;
	if (k > n * n / 4) {	// 구현 불가능
		cout << -1;
		return 0;
	}

	// 2. solve(greedy)
	int a = n / 2, b = n - a;
	vector<int> cnt(b + 1);		// A가 위치할 수 있는 공간의 a를 담고 있는 배열
	for (int i = 0; i < a; i++) {
		int x = min(b, k);
		cnt[b - x]++;
		k -= x;
	}
	for (int i = 0; i < b + 1; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			cout << 'A';
		}
		if (i < b) {	// 맨 뒤에는 B를 출력하지 않음.
			cout << 'B';
		}
	}
	return 0;
}
