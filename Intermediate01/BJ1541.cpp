#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> num;
vector<char> op;

// 처음으로 -가 나온 이후에는 모두 마이너스로 계산

int main() {
	// 1. input
	string str;
	cin >> str;
	int start = 0;
	for (int i = 0; i < str.size() + 1; i++) {
		if (i == str.size()) {
			num.push_back(stoi(str.substr(start, i - start)));
		}
		else if (str[i] == '+' || str[i] == '-') {
			num.push_back(stoi(str.substr(start, i - start)));
			start = i + 1;
			op.push_back(str[i]);
		}
	}

	// 2. solve (greedy)
	int idx = -1, sum = 0;
	for (int i = 0; i < op.size(); i++) {
		if (op[i] == '-') {
			idx = i;
			break;
		}
	}
	for (int i = 0; i < num.size(); i++) {
		if (idx != -1 && i > idx) {
			sum -= num[i];
		}
		else {
			sum += num[i];
		}
	}
	cout << sum;
	return 0;
}