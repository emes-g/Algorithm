#include <iostream>
#include <string>
using namespace std;

int main() {
	int cnt = 0;	// �߷��� �踷��� ������ �� ����
	int num = 0;	// ���� �踷����� ����
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