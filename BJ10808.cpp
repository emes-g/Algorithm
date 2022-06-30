#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int cnt[26];
	fill_n(cnt, 26, 0);
	for (char ch : str) {
		cnt[ch - 'a']++;
	}
	for (int i : cnt) {
		cout << i << ' ';
	}
	return 0;
}
