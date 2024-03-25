#include <iostream>
#include <queue>
using namespace std;
const int MAX = 10000;
bool check[MAX];

// <차이점>
// pair를 통해 문자열을 계속해서 기억하는 방식 (참고 X)
// 2168KB/4144MS

// 기본적인 역추적 방식으로 구현하고 싶다면 역추적 버전 참고!

pair<int, char> calc(int x, int op) {
	switch (op) {
	case 0:
		return { (x * 2) % MAX, 'D' };
	case 1:
		return { (x ? x - 1 : 9999) , 'S' };
	case 2:
		x *= 10;
		x = x % MAX + x / MAX;
		return { x, 'L' };
	case 3:
		int temp = x % 10;
		x += (temp * MAX);
		x /= 10;
		return { x, 'R' };
	}
}

void bfs(int x, string str, int B) {
	queue<pair<int, string>> q;
	q.push({ x,str });
	check[x] = true;
	while (!q.empty()) {
		x = q.front().first;
		str = q.front().second;
		q.pop();
		if (x == B) {
			cout << str << '\n';
			return;
		}
		for (int i = 0; i < 4; i++) {
			pair<int, char> res = calc(x, i);
			if (!check[res.first]) {
				q.push({ res.first, str + res.second });
				check[res.first] = true;
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int A, B;
		cin >> A >> B;
		bfs(A, "", B);
		fill_n(check, MAX, false);
	}
}