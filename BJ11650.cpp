#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}

	// 2. solve
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		cout << a[i].first << ' ' << a[i].second << '\n';
	}
}