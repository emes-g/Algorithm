#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char c[9];

bool good(vector<int>& vec, int k) {
	for (int i = 0; i < k; i++) {
		if (c[i] == '<') {
			if (vec[i] > vec[i + 1]) {
				return false;
			}
		}
		else {
			if (vec[i] < vec[i + 1]) {
				return false;
			}
		}
	}
	return true;
}

void print(vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i];
	}
	cout << '\n';
}

int main() {
	// 1. input
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> c[i];
	}

	// 2. solve (permutation)
	vector<int> big(k + 1), small(k + 1);
	for (int i = 0; i <= k; i++) {
		big[i] = 9 - i;
		small[i] = i;
	}	
	do {
		if (good(big, k)) {
			break;
		}
	} while (prev_permutation(big.begin(), big.end()));
	do {
		if (good(small, k)) {
			break;
		}
	} while (next_permutation(small.begin(), small.end()));

	// 3. output
	print(big);
	print(small);
}