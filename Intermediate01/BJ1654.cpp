#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
vector<int> a;

// 헷갈리게 풀지 말자.
// 왜 가장 긴 길이를 지닌 랜선을 냅두고,
// 가장 짧은 길이를 지닌 랜선으로 문제를 해결하려 하는거야!

// <주의 사항>
// 1. 랜선의 길이가 2^31 - 1이고, 1cm 단위로 랜선을 자른다고 하면,
// long long의 범위가 필요하다.
// 2. 자를 랜선 단위의 길이가 0이면 안 된다.
// → binary_search 함수의 첫 번째 인자로는 반드시 1이 들어가야 한다.

bool good(long long mid) {
	long long cnt = 0;
	for (int i = 0; i < k; i++) {
		cnt += a[i] / mid;
	}
	return cnt < n;
}

long long binary_search(long long left, long long right) {
	while (left <= right) {
		long long mid = (left + right) / 2;
		if (good(mid)) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return right;
}

int main() {
	// 1. input
	cin >> k >> n;
	a.resize(k);
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}

	// 2. solve (binary_search)
	sort(a.begin(), a.end());
	cout << binary_search(1, a[k - 1]);
}