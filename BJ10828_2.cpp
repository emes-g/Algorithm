#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	stack<int> s;

	while (n--) {
		string str;
		cin >> str;
		if (str == "push") {
			int x;
			cin >> x;
			s.push(x);
		}
		else if (str == "top") {
			cout << (s.empty() ? -1 : s.top()) << '\n';
		}
		else if (str == "size") {
			cout << s.size() << '\n';
		}
		else if (str == "empty") {
			cout << (s.empty() ? 1 : 0) << '\n';
		}
		else if (str == "pop") {
			cout << (s.empty() ? -1 : s.top()) << '\n';
			if (!s.empty()) {
				s.pop();
			}
		}
		else {
			return -1;
		}
	}
}
