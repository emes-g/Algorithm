#include <iostream>
#include <vector>
using namespace std;

int gcd(int x, int y) {
	int mod = x % y;
	while (mod != 0) {
		x = y;
		y = mod;
		mod = x % y;
	}
	return y;
}

int main() {
	int n, s;
	cin >> n >> s;
	vector<int> dis(n);	// 수빈이와 동생 간 거리
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		dis[i] = abs(s - temp);
	}
	
	int d = dis[0];
	for (int i = 1; i < n; i++) {
		d = gcd(d, dis[i]);
	}
	cout << d;
	return 0;
}