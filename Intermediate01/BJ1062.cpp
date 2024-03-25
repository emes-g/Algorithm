#include <iostream>
#include <vector>
using namespace std;
int n, k, ans;
bool check[26];
vector<string> word;

// 예상 시간복잡도 : O(2^21 * 50 * 7)
// ∵ 21개의 숫자 선택, 단어 50개, 단어 15글자

// 2024kb/368ms
// 왜 예상 시간보다 훨씬 빠를까?

void init() {	// 사전 설정
	char temp[5] = { 'a','n','t','i','c' };
	for (char ch : temp) {
		check[ch - 'a'] = true;
	}
	k -= 5;
}

bool good(string str) {
	for (char ch : str) {
		if (!check[ch - 'a']) {
			return false;
		}
	}
	return true;
}

void go(int level, int index) {
	if (level == k) {
		int cnt = 0;
		for (string str : word) {
			if (good(str)) {
				cnt++;
			}
		}
		ans = max(ans, cnt);
		return;
	}
	else if (index >= 26) {
		return;
	}
	else if (check[index]) {	// a, n, t, i, c (사전 설정)
		index++;
	}
	check[index] = true;
	go(level + 1, index + 1);
	check[index] = false;
	go(level, index + 1);
}

int main() {
	// 1. input
	cin >> n >> k;
	if (k < 5) {
		cout << 0;
		return 0;
	}
	init();
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		str = str.substr(4, str.size() - 8);
		word.push_back(str);
	}

	// 2. solve (brute force)
	go(0, 0);
	cout << ans;
}
