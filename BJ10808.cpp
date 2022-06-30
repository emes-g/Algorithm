#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string str;
	cin >> str;
	int cnt[26]{ 0 };
	for (char ch : str) {
		cnt[ch - 'a']++;
	}
	for (int i : cnt) {
		cout << i << ' ';
	}
}