#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1000000000;
const int MIN = -1000000000;
int a[11];
vector<int> op;

int calc(int res, int num, int op) {
	switch (op) {
	case 0:
		res += num;
		break;
	case 1:
		res -= num;
		break;
	case 2:
		res *= num;
		break;
	case 3:
		res /= num;
		break;
	}
	return res;
}

int main() {
	// 1. input
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++) {
		int x;
		cin >> x;
		while (x--) {
			op.push_back(i);
		}
	}
	
	// 2. solve (permutation)
	pair<int, int> ans = { MIN,MAX };
	do {
		int res = a[0];
		for (int i = 1; i < n; i++) {
			res = calc(res, a[i], op[i - 1]);
		}
		ans.first = max(ans.first, res);
		ans.second = min(ans.second, res);
	} while (next_permutation(op.begin(), op.end()));

	// 3. output
	cout << ans.first << '\n';
	cout << ans.second;
}
