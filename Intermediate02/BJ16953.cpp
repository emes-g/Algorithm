#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int a, b, ans = 32;

void go(int level, ll val) {
	if (val == b) {
		ans = min(ans, level);
		return;
	}
	else if (val > b) {
		return;
	}
	go(level + 1, val * 2);
	go(level + 1, val * 10 + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> a >> b;
	go(0, a);
	cout << (ans == 32 ? -1 : ans + 1);
}