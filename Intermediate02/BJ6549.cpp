#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<int> a;

ll histogram(int start, int end) {
	if (start == end) {
		return a[start];
	}
	int mid = (start + end) / 2;
	ll L = histogram(start, mid);
	ll R = histogram(mid + 1, end);

	int i = mid;
	int j = mid + 1;
	int curWidth = j - i + 1;
	int curHeight = min(a[i], a[j]);
	ll curArea = curHeight * 2;
	ll C = curArea;
	while (i - 1 >= start && j + 1 <= end) {
		if (a[i - 1] >= a[j + 1]) {
			curHeight = min(curHeight, a[--i]);
		}
		else {
			curHeight = min(curHeight, a[++j]);
		}
		curArea = 1LL * curHeight * ++curWidth;
		C = max(C, curArea);
	}
	while (i - 1 >= start) {
		curHeight = min(curHeight, a[--i]);
		curArea = 1LL * curHeight * ++curWidth;
		C = max(C, curArea);
	}
	while (j + 1 <= end) {
		curHeight = min(curHeight, a[++j]);
		curArea = 1LL * curHeight * ++curWidth;
		C = max(C, curArea);
	}
	
	return max(max(L, R), C);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true) {
		// 1. input
		int n;
		cin >> n;
		if (n == 0) {
			return 0;
		}
		a.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		// 2. solve
		cout << histogram(0, n - 1) << '\n';
	}
}