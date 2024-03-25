#include <iostream>
using namespace std;

int main() {
	int E, S, M;
	cin >> E >> S >> M;

	for (int i = 1; i <= 7980; i++) {
		int e = (i % 15 == 0) ? 15 : i % 15;
		int s = (i % 28 == 0) ? 28 : i % 28;
		int m = (i % 19 == 0) ? 19 : i % 19;
		if (e == E && s == S && m == M) {
			cout << i;
			return 0;
		}
	}
}
