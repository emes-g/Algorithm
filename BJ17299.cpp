#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> ngf(n, -1);
	map<int, int> f;
	stack<int> s;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		f[a[i]]++;
	}

	/* f-value ∞À¡ı
	map<int, int>::iterator it = f.begin();
	while (it != f.end()) {
		cout << it->second << ' ';
		it++;
	}*/

	for (int i = 0; i < n; i++) {
		while (!s.empty() && f[a[s.top()]] < f[a[i]]) {
			ngf[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i : ngf) {
		cout << i << ' ';
	}
}