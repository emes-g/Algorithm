#include <iostream>
using namespace std;

struct bitmask {
	// 1. init
	int s;
	bitmask() {
		s = 0;
	}

	// 2. function
	void add(int x) {
		s |= (1 << x);
	}
	void remove(int x) {
		s &= ~(1 << x);
	}
	int check(int x) {
		if (s & (1 << x)) {
			return 1;
		}
		else {
			return 0;
		}
	}
	void toggle(int x) {
		s ^= (1 << x);
	}
	void all() {
		s = (1 << 21) - 1;
	}
	void empty() {
		s = 0;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int m, x;
	cin >> m;
	bitmask b;

	while (m--) {
		string cmd;
		cin >> cmd;
		if (cmd == "add") {
			cin >> x;
			b.add(x);
		}
		else if (cmd == "check") {
			cin >> x;
			cout << b.check(x) << '\n';
		}
		else if (cmd == "remove") {
			cin >> x;
			b.remove(x);
		}
		else if (cmd == "toggle") {
			cin >> x;
			b.toggle(x);
		}
		else if (cmd == "all") {
			b.all();
		}
		else {
			b.empty();
		}
	}
	return 0;
}