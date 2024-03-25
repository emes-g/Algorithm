#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<pair<ll, ll>> a;

// <문제 파악>
// 앞에 위치하는 수를 3으로 나누기 때문에,
// 앞에 위치하는 수가 인수 3을 더 많이 가지고 있어야 한다.
// → 3의 개수에 따라 내림차순 정렬

// 뒤에 위치하는 수가 인수 2를 더 많이 가지고 있어야 한다.
// → 3의 개수가 똑같다면, 2의 개수에 따라 오름차순 정렬

int main() {
	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		ll temp = a[i].first;
		while (temp % 3 == 0) {
			temp /= 3;
			a[i].second++;
		}
	}
	sort(a.begin(), a.end(), [](auto x, auto y) {
		if (x.second == y.second) {
			return x.first < y.first;
		}
		else {
			return x.second > y.second;
		}
		});

	for (int i = 0; i < n; i++) {
		cout << a[i].first << ' ';
	}
}