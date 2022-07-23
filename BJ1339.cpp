#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<string> word;
int check[26];

// 테스트 케이스는 전부 해결되지만 시간 초과
// 소요 시간 : O(26 * 100 * 10!) (최악의 경우)

int main() {
	int n, size = 0;
	cin >> n;
	fill_n(check, 26, -1);
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		word.push_back(str);
		for (int j = 0; j < str.size(); j++) {
			int idx = str[j] - 'A';
			if (check[idx] == -1) {
				check[idx] = size++;
			}
		}
	}

	vector<int> num(size);
	for (int i = 0; i < size; i++) {
		num[i] = 9 - i;
	}

	int ans = 0;
	do {
		// 매칭
		int idx = 0;
		for (int i = 0; i < 26; i++) {
			if (check[i] != -1) {
				check[i] = num[idx++];
			}
		}

		// 구현
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int temp = 0;
			for (int j = 0; j < word[i].size(); j++) {
				idx = word[i][j] - 'A';
				temp += check[idx] * pow(10, word[i].size() - 1 - j);
			}
			sum += temp;
		}
		ans = max(ans, sum);
	} while (prev_permutation(num.begin(), num.end()));
	cout << ans;
}