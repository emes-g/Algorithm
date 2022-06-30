#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int cnt[4];
	while(true){
		fill_n(cnt, 4, 0);
		getline(cin, str);	// 개행 전까지 입력받고, 개행은 버린다.
		if (str.size() == 0)	break;
		for (char ch : str) {
			if (ch >= 'a' && ch <= 'z') {
				cnt[0]++;
			}
			else if (ch >= 'A' && ch <= 'Z') {
				cnt[1]++;
			}
			else if (ch >= '0' && ch <= '9') {
				cnt[2]++;
			}
			else {
				cnt[3]++;
			}
		}
		for (int i : cnt) {
			cout << i << ' ';
		}
		cout << '\n';
	}
}