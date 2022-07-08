#include <iostream>
using namespace std;

int main() {
	int e, s, m;
	cin >> e >> s >> m;

	for (int i = 1; i <= 7980; i++) {
		if ((i % 15 == e || i % 15 + 15 == e) && 
			(i % 28 == s || i % 28 + 28 == s) && 
			(i % 19 == m || i % 19 + 19 == m)) {
			cout << i;
			return 0;
		}
	}
}