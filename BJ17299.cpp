#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 배열의 random access는 인덱스를 통해 접근하므로 O(1)에 해결되지만,
// map은 검색 시간이 O(logN)이다.
// 이를 통해 map으로 구현하면 배열보다 시간이 오래 걸릴 수 있음에 주의해야 한다.

int f[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> ngf(n, -1);
	stack<int> s;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		f[a[i]]++;
	}

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
