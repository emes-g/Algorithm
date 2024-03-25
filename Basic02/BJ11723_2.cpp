#include <iostream>
#include <bitset>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int m, x;
	cin >> m;
	bitset<21> b;

	while (m--) {
		string cmd;
		cin >> cmd;
		if (cmd == "add") {
			cin >> x;
			b[x] = 1;
		}
		else if (cmd == "check") {
			cin >> x;
			cout << (b[x] == 1 ? 1 : 0) << '\n';
		}
		else if (cmd == "remove") {
			cin >> x;
			b[x] = 0;
		}
		else if (cmd == "toggle") {
			cin >> x;
			b.flip(x);
		}
		else if (cmd == "all") {
			b.set();
		}
		else {
			b.reset();
		}
	}
	return 0;
}