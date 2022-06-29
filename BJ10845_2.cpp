#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	queue<int> q;
	cin >> n;
	while (n--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			int x;
			cin >> x;
			q.push(x);
		}
		else if (cmd == "front") {
			if (!q.empty()) {
				cout << q.front() << '\n';
			}
		}
		else if (cmd == "back") {
			if (!q.empty()) {
				cout << q.back() << '\n';
			}
		}
		else if (cmd == "size") {
			cout << q.size() << '\n';
		}
		else if (cmd == "empty") {
			cout << (q.empty() ? 1 : 0) << '\n';
		}
		else {
			if (!q.empty()) {
				cout << q.front() << '\n';
				q.pop();
			}
			else {
				cout << -1 << '\n';
			}
		}
	}
	return 0;
}