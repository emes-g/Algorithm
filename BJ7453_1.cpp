#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 4000;
int a[MAX], b[MAX], c[MAX], d[MAX];

// <문제 파악>
// 두 배열 각각에서 포인터를 하나씩 사용하는 투 포인터 문제로,
// '중간에서 만나기' 기법을 이용해 문제 크기를 N^4에서 N^2으로 줄이고 문제를 해결한다.

// <알고리즘>
// 1. 두 배열씩 묶어서 합을 새로운 배열에 저장한다.
// 2. 합 배열을 정렬한다.
// 3. 투 포인터로 문제를 해결한다.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// 1. input
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	// 2. solve (meet in the middle & two pointer)
	vector<int> x, y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			x.push_back(a[i] + b[j]);
			y.push_back(c[i] + d[j]);
		}
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end(), greater<int>());

	ll i = 0, j = 0, ans = 0;
	int X = x.size(), Y = y.size(), sum = 0;
	while (i < X && j < Y) {
		sum = x[i] + y[j];
		if (sum < 0) {
			i++;
		}
		else if (sum > 0) {
			j++;
		}
		else {
			ll idx1 = i + 1, idx2 = j + 1;
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
