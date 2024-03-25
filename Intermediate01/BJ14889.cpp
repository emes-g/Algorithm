#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 10000;
int s[20][20], start[10], link[10];
vector<int> a;

int main() {
	// 1. input
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}
	
	// 2. solve (permutation)
	int ans = MAX;
	for (int i = 0; i < n / 2; i++) {
		a.push_back(1);
		a.push_back(2);
	}
	sort(a.begin(), a.end());
	do {
		int idx[2] = { 0,0 };
		for (int i = 0; i < n; i++) {
			if (a[i] == 1) {
				start[idx[0]++] = i;
			}
			else {
				link[idx[1]++] = i;
			}
		}

		int sum[2] = { 0,0 };
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				if (i != j) {
					sum[0] += s[start[i]][start[j]];
					sum[1] += s[link[i]][link[j]];
				}
			}
		}

		ans = min(ans, abs(sum[0] - sum[1]));
	} while (next_permutation(a.begin(), a.end()));

	// 3. output
	cout << ans;
}