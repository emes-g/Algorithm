#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool binary_search(vector<int>& a, int num) {
	int l = 0;
	int r = a.size() - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (a[m] == num) {
			return true;
		}
		else if (a[m] > num) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		cout << binary_search(a, num) << ' ';
	}
}