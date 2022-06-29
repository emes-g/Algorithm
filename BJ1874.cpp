#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	stack<int> s;
	int m = 1;	// ���ÿ� �߰��� ��
	string ans;	// ����� ����

	while (n--) {
		int num;
		cin >> num;

		if (m <= num) {
			while (m <= num) {
				s.push(m++);
				ans += "+\n";
			}
			s.pop();
			ans += "-\n";
		}
		else {
			if (s.top() == num) {
				s.pop();
				ans += "-\n";
			}
			else {
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << ans;
	return 0;
}