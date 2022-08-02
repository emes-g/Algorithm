#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX = 1000000;
int a[MAX], idx[MAX];

// 시간복잡도 : O(nlogn)
// LIS 5와 코드가 동일하므로 해당 파일 참고

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. LIS 구하기 (길이)
	int n;
	cin >> n;
	vector<int> sub;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		auto it = lower_bound(sub.begin(), sub.end(), a[i]);
		idx[i] = it - sub.begin();
		if (it == sub.end()) {
			sub.push_back(a[i]);
		}
		else {
			*it = a[i];
		}
	}
	cout << sub.size() << '\n';

	// 2. tracking (using idx)
	stack<int> s;
	int cnt = sub.size() - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (cnt < 0) {
			break;
		}
		else if (idx[i] == cnt) {
			s.push(a[i]);
			cnt--;
		}
	}
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
}
