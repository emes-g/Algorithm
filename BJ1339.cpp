#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int weight[26];

// <수정>
// 모든 경우의 수를 순열로 해 볼 필요없이
// 알파벳마다 가중치를 주어, 높은 가중치를 가진 알파벳에 높은 숫자를 부여한다.

int main() {
	int n, size = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			int idx = str[j] - 'A';
			weight[idx] += pow(10, str.size() - 1 - j);
		}
	}

	int sum = 0, num = 9;
	sort(weight, weight + 26, greater<int>());
	for (int i = 0; i < 26; i++) {
		if (weight[i] == 0) {
			cout << sum;
			return 0;
		}
		sum += weight[i] * num--;
	}
}
