#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// string substr(시작 위치, 길이)
// 시작 위치부터 길이 만큼의 문자열 반환

// void sort(첫번째 주소, 마지막 주소, 정렬형태)
// ex) sort(arr, arr+size, less<int>())
// ex) sort(v.begin(), v.end())

int main() {
	string str;
	cin >> str;

	size_t size = str.size();
	vector<string> suffix;

	for (int i = 0; i < size; i++) {
		suffix.push_back(str.substr(i, size - i));
	}
	sort(suffix.begin(), suffix.end(), [](string x, string y) {
		return x < y;
		});
	for (string s : suffix) {
		cout << s << '\n';
	}
	return 0;
}