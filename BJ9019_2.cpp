#include <iostream>
#include <queue>
#include <stack>
using namespace std;
const int MAX = 10000;
int dist[MAX], from[MAX];
char op[MAX];

// 경로를 출력하는 역추적 문제
// 유사 : 숨바꼭질 4 (13913)

// dist[i] : 해당 숫자를 표현하기 위한 최소 횟수
// from[i] : 해당 숫자를 표현하기 위해 어떤 숫자에서 왔는지 기록
// op[i]   : 해당 숫자를 표현하기 위해 어떤 연산으로 왔는지 기록

void init() {
	fill_n(dist, MAX, -1);
	fill_n(from, MAX, 0);
	fill_n(op, MAX, ' ');
}

int calc(int x, int op) {
	switch (op) {
	case 0:
		return (x * 2) % MAX;
	case 1:
		return (x ? x - 1 : 9999);
	case 2:
		x *= 10;
		return x % MAX + x / MAX;
	case 3:
		int temp = x % 10;
		x += (temp * MAX);
		return x / 10;
	}
}

char to_op(int num) {
	switch (num) {
	case 0:
		return 'D';
	case 1:
		return 'S';
	case 2:
		return 'L';
	case 3:
		return 'R';
	}
}

void print(int b) {
	stack<char> s;
	while (from[b] != -1) {
		s.push(op[b]);
		b = from[b];
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << '\n';
}

void bfs(int x, int b) {
	queue<int> q;
	q.push(x);
	dist[x] = 0;
	from[x] = -1;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		if (x == b) {
			print(b);
			return;
		}
		for (int k = 0; k < 4; k++) {
			int res = calc(x, k);
			if (dist[res] == -1) {
				dist[res] = dist[x] + 1;
				from[res] = x;
				op[res] = to_op(k);
				q.push(res);
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		init();
		bfs(a, b);
	}
}