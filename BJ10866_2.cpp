#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	deque<int> d;
	cin >> n;
	while (n--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push_front") {
			int x;
			cin >> x;
			d.push_front(x);
		}
		else if (cmd == "push_back") {
			int x;
			cin >> x;
			d.push_back(x);
		}
		else if (cmd == "pop_front") {
			if (d.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << d.front() << '\n';
				d.pop_front();
			}
		}
		else if (cmd == "pop_back") {
			if (d.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << d.back() << '\n';
				d.pop_back();
			}
		}
		else if (cmd == "front") {
			cout << (d.empty() ? -1 : d.front())<< '\n';
		}
		else if (cmd == "back") {
			cout << (d.empty() ? -1 : d.back())<< '\n';
		}
		else if (cmd == "size") {
			cout << d.size() << '\n';
		}
		else {
			cout << (d.empty() ? 1 : 0) << '\n';
		}
	}
	return 0;
}