#include <iostream>
#include <set>
using namespace std;
int n, ans;
set<int> s;
bool check[21][21][21][21];

void go(int level, int i, int v, int x, int l, int sum) {
	if (check[i][v][x][l]) {
		return;
	}
	else if (level == n) {
		check[i][v][x][l] = true;
		if (s.find(sum) == s.end()) {
			s.insert(sum);
			ans++;
		}
		return;
	}
	check[i][v][x][l] = true;
	go(level + 1, i + 1, v, x, l, sum + 1);
	go(level + 1, i, v + 1, x, l, sum + 5);
	go(level + 1, i, v, x + 1, l, sum + 10);
	go(level + 1, i, v, x, l + 1, sum + 50);
}

int main() {
	cin >> n;
	go(0, 0, 0, 0, 0, 0);
	cout << ans;
}