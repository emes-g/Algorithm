#include <iostream>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	set<string, greater<string>> s;
	int n;
	cin >> n;
	while (n--) {
		string str, str2;
		cin >> str >> str2;
		if (str2 == "enter") {
			s.insert(str);
		}
		else {
			s.erase(str);
		}
	}
	for (auto it = s.begin(); it != s.end(); it++) {
		cout << *it << '\n';
	}
}