#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	const int MAX = 1000000;
	vector<bool> check(MAX + 1, true);
	for (int i = 2; i * i <= MAX; i++) {
		if (check[i]) {
			for (int j = i * i; j <= MAX; j += i) {
				check[j] = false;
			}
		}
	}

	while (true) {
		int i, num;
		cin >> num;
		if (num == 0) {
			break;
		}
		for (i = 3; i <= num / 2; i++) {
			if (check[i] && check[num - i]) {
				cout << num << " = " << i << " + " << num - i << '\n';
				break;
			}
		}
		if (i > num / 2) {
			cout << "Goldbach's conjecture is wrong.\n";
		}
	}
	return 0;
}