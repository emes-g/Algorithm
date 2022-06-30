#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int cnt[26];
	fill_n(cnt, 26, -1);
	for (int i = 0; i < str.size(); i++) {
		if (cnt[str[i] - 'a'] == -1) {
			cnt[str[i] - 'a'] = i;
		}
	}
	for (int i : cnt) {
		cout << i << ' ';
	}
	return 0;
} 
