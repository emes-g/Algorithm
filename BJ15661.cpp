#include <iostream>
#include <vector>
using namespace std;
const int MAX = 20000;
int s[20][20], ans = MAX;
vector<int> first, second;

void go(int index, int n) {
	if (first.size() + second.size() == n) {
		int total[2] = { 0 };
		for (int i = 0; i < first.size(); i++) {
			for (int j = 0; j < first.size(); j++) {
				if (i != j) {
					total[0] += s[first[i]][first[j]];
				}
			}
		}
		for (int i = 0; i < second.size(); i++) {
			for (int j = 0; j < second.size(); j++) {
				if (i != j) {
					total[1] += s[second[i]][second[j]];
				}
			}
		}
		ans = min(ans, abs(total[0] - total[1]));
		return;
	}
	first.push_back(index);
	go(index + 1, n);
	first.pop_back();
	second.push_back(index);
	go(index + 1, n);
	second.pop_back();
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}
	go(0, n);
	cout << ans;
	return 0;
}