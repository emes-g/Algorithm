#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1000;
int a[MAX], b[MAX];

// <문제 파악>
// 한 배열에서 투 포인터를 사용하는 것이 아닌,
// 두 배열 각각에서 포인터를 하나씩 사용하는 문제

// <알고리즘>
// 1. 각 배열에 존재하는 모든 부 배열의 합을 구한다.
// 2. 하나는 오름차순, 다른 하나는 내림차순으로 정렬한다.
// 3. 투 포인터로 문제를 해결한다.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// 1. input
	int t, n, m;
	cin >> t >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	// 2. solve (two pointer)
	int sum;
	vector<int> x, y;
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = i; j < n; j++) {
			sum += a[j];
			x.push_back(sum);
		}
	}
	for (int i = 0; i < m; i++) {
		sum = 0;
		for (int j = i; j < m; j++) {
			sum += b[j];
			y.push_back(sum);
		}
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end(), greater<int>());

	long long i = 0, j = 0, ans = 0;
	int X = x.size(), Y = y.size();
	while (i < X && j < Y) {
		sum = x[i] + y[j];
		if (sum < t) {
			i++;
		}
		else if (sum > t) {
			j++;
		}
		else {
			int idx1 = i + 1, idx2 = j + 1;
			while (idx1 < X && x[idx1] == x[i]) {
				idx1++;
			}
			while (idx2 < Y && y[idx2] == y[j]) {
				idx2++;
			}
			ans += (idx1 - i) * (idx2 - j);
			i = idx1;
			j = idx2;
		}
	}
	cout << ans;
}