#include <iostream>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// 1. input
	set<string> s, ans;
	int n, m;
	cin >> n >> m;
	
	// 2. solve
	for (int i = 0; i < n + m; i++) {
		string str;
		cin >> str;
		if (s.find(str) != s.end()) {
			ans.insert(str);
		}
		else {
			s.insert(str);
		}
	}
	
	// 3. output
	cout << ans.size() << '\n';
	for (auto it = ans.begin(); it != ans.end(); it++) {
		cout << *it << '\n';
	}
}
