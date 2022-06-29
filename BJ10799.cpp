#include <iostream>
#include <string>
using namespace std;

int main() {
	int cnt = 0;	// 잘려진 쇠막대기 조각의 총 개수
	int num = 0;	// 현재 쇠막대기의 개수
	string str;
	cin >> str;
	for (size_t i = 0; i < str.size() - 1; i++) {
		if (str[i] == '(' && str[i + 1] == ')') {	// lazer
			cnt += num;
		}
		else if (str[i] == '(' && str[i + 1] == '(') {
			num++;
			cnt++;
		}
		else if (str[i] == ')' && str[i + 1] == ')') {
			num--;
		}
	}
	cout << cnt;
	return 0;
}