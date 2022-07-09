#include <iostream>
#include <vector>
using namespace std;
bool check[9];
vector<int> num;

// 시간복잡도 : O(N^M)

void BT(int n, int m, int level) {
	if (level == m + 1) {
		for (int i = 0; i < num.size(); i++) {
			cout << num[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			check[i] = true;
			num.push_back(i);
			BT(n, m, level + 1);
			check[i] = false;
			num.pop_back();
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	BT(n, m, 1);
	return 0;
}
