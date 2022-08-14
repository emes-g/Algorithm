#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
const int MAX = 1000000000;
using namespace std;
vector<int> a;

int calc() {
	if (a[0] == 0) {
		return MAX;
	}
	int sum = 0, n = a.size();
	for (int i = 0; i < n; i++) {
		sum += a[i] * pow(10, n - 1 - i);
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	string str;
	cin >> str;
	int n = str.size();
	a.resize(n);
	for (int i = 0; i < n; i++) {
		a[i] = str[i] - '0';
	}
	sort(a.begin(), a.end(), greater<int>());
	int B, C;
	cin >> B;
	n = to_string(B).size();

	// 2. solve (brute force)
	if (a.size() <= n) {
		do {
			C = calc();
			if (C < B) {
				cout << C;
				return 0;
			}
		} while (prev_permutation(a.begin(), a.end()));
		cout << -1;
	}
	else {
		cout << -1;
	}
}