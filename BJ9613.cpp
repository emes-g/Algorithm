#include <iostream>
#include <string>
#include <vector>
using namespace std;

int gcd(int x, int y) {
	if (x < y) {	// �׻� x�� y���� ������ �ִ�.
		int temp = x;
		x = y;
		y = temp;
	}

	int mod = x % y;
	while (mod != 0) {
		x = y;
		y = mod;
		mod = x % y;
	}
	return y;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> num(n);
		long long sum = 0;	// n�� 100�̰� 100���� �� ���� 100���̶�� �����ϸ�, sum�� 49.5���� �����Ƿ� int�δ� �Ұ����ϴ�. 
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}

		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				sum += gcd(num[i], num[j]);
			}
		}
		cout << sum << '\n';
	}
	return 0;
}