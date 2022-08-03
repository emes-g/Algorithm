#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// <가능한 경우 탐색>
// 1. N >= M+K-1
// 왜?
// 적어도 M개의 정수는 증가 수열에 포함,
// 적어도 K개의 정수는 감소 수열에 포함,
// 또한 최대 1개의 정수를 공유할 수 있다.
// ex) a : 1 2 4 3
// 2. N <= MK (비둘기집의 원리)
// 왜?
// 크기가 K인 그룹 M개로 구성된 수열이 있다고 하자.
// 해당 수열에 수 하나를 추가하는데,
// 이때 다른 그룹에 추가하거나 새로운 그룹에 넣는다고 하자. 
// (N = MK + 1이라고 해보자)
// 그러면 크기가 K+1인 그룹이 생기거나, 그룹의 개수가 M+1이 되어버린다.
// 위 상황은 LIS의 길이가 M이고, LDS의 길이가 K라는 조건에 모순되므로 발생해서는 안 된다.
// 따라서 길이가 N인 수열이 길이가 M인 LIS와 길이가 K인 LDS를 갖기 위해서는 N <= MK를 만족해야 한다.
// ∴ M+K-1 <= N <= MK

// <프로세스>
// 1. N 이하의 자연수를 한 번씩만 사용하여 만든 수열을 오름차순 정렬한다.
// 2. 해당 수열을 M등분한다. 
// (단, 각 그룹의 크기는 K 이하이며 반드시 한 그룹은 크기가 K여야 한다)
// 3. 각 그룹에 들어있는 수의 순서를 뒤집는다.

int main() {
	// 1. input
	int n, m, k;
	cin >> n >> m >> k;
	if (n < m + k - 1 || n > m * k) {
		cout << -1;
		return 0;
	}

	// 2. solve
	vector<int> a(n), g;	// g : 그룹을 구분하는 인덱스
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	g.push_back(0);
	g.push_back(k);
	n -= k;
	m -= 1;
	if (m != 0) {	// m == 0이면 더 이상 그룹을 만들지 않으므로 아래 과정을 거칠 필요가 없다.
		int gs = n / m;	// 그룹의 크기
		int r = n % m;	// 크기가 더 큰 그룹의 개수
		for (int i = 0; i < m; i++) {
			g.push_back(g.back() + gs + (r ? 1 : 0));
			if (r) {
				r--;
			}
		}
	}
	for (int i = 0; i < g.size() - 1; i++) {
		reverse(a.begin() + g[i], a.begin() + g[i + 1]);
	}
	for (int i : a) {
		cout << i << ' ';
	}
}
