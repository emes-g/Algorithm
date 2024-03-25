#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char c[9];

// 시간복잡도 : O(k * k!)

bool good(vector<int>& vec, int k) {
	for (int i = 1; i <= k; i++) {
		char sign = c[i - 1];
		if (sign == '<') {
			if (vec[i - 1] > vec[i]) {
				return false;
			}
		}
		else {
			if (vec[i - 1] < vec[i]) {
				return false;
			}
		}
	}
	return true;
}

void print(vector<int>& vec, int k) {
	for (int i = 0; i <= k; i++) {
		cout << vec[i];
	}
	cout << '\n';
	return;
}

int main() {
	// 1. input
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> c[i];
	}
	
	// 2. solve (permutation)
	vector<int> small(k + 1), big(k + 1);
	for (int i = 0; i <= k; i++) {
		small[i] = i;
		big[i] = 9 - i;
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
	print(big, k);
	print(small, k);
	return 0;
}