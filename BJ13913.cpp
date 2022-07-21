#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
const int MAX = 200000;
int a[MAX], parent[MAX];
stack<int> s;

void bfs(int n, int k) {
	queue<int> q;
	q.push(n);
	a[n] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		int next[3] = { x + 1,x - 1,2 * x };
		for (int i = 0; i < 3; i++) {
			if (next[i] >= 0 && next[i] < MAX && a[next[i]] > a[x] + 1) {
				q.push(next[i]);
				a[next[i]] = a[x] + 1;
				parent[next[i]] = x;
			}
		}
	}

	s.push(k);
	while (s.top() != n) {
		k = parent[k];
		s.push(k);
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	fill_n(a, MAX, MAX);
	fill_n(parent, MAX, MAX);
	bfs(n, k);
	cout << a[k] << '\n';
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
}