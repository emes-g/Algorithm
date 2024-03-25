#include <iostream>
#include <queue>
#include <cmath>
#include <string>
using namespace std;
const int MAX = 10000;
bool prime[MAX];
int a, b, dist[MAX];

void eratos() {
	fill_n(prime, MAX, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i * i < MAX; i++) {
		if (prime[i]) {
			for (int j = i * 2; j < MAX; j += i) {
				prime[j] = false;
			}
		}
	}
}

string bfs() {
	fill_n(dist, MAX, -1);
	queue<int> q;
	q.push(a);
	dist[a] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == b) {
			return to_string(dist[b]);
		}

		// 각 자릿수 확보
		// ex) 1033 → num = {3, 3, 0, 1}
		int num[4], temp = x;
		for (int i = 0; i < 4; i++) {
			num[i] = temp % 10;
			temp /= 10;
		}

		for (int k = 3; k >= 0; k--) {
			temp = pow(10, k);
			for (int i = 0; i < 10; i++) {
				if (k == 3 && i == 0) {
					continue;
				}
				int next = x - (num[k] * temp) + (i * temp);
				if (prime[next] && dist[next] == -1) {
					dist[next] = dist[x] + 1;
					q.push(next);
				}
			}
		}
	}
	return "Impossible";
}

int main() {
	eratos();
	int t;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << bfs() << '\n';
	}
}