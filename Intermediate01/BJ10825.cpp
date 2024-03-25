#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
typedef tuple<string, int, int, int> t;

bool cmp(t x, t y) {
	string a1, a2;
	int b1, b2, c1, c2, d1, d2;
	tie(a1, b1, c1, d1) = x;
	tie(a2, b2, c2, d2) = y;
	if (b1 == b2) {
		if (c1 == c2) {
			if (d1 == d2) {
				return a1 < a2;
			}
			else {
				return d1 > d2;
			}
		}
		else {
			return c1 < c2;
		}
	}
	else {
		return b1 > b2;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n;
	cin >> n;
	vector<t> a(n);
	for (int i = 0; i < n; i++) {
		string name;
		int kor, eng, math;
		cin >> name >> kor >> eng >> math;
		a[i] = { name,kor,eng,math };
	}

	// 2. solve
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i < n; i++) {
		string name = get<0>(a[i]);
		cout << name << '\n';
	}
}