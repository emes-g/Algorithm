#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	queue<int> q;

	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}

	cout << "<";
	while (!q.empty()) {
		for (int i = 0; i < k; i++) {
			if (i != k - 1) {
				q.push(q.front());
			}
			else {
				string dlim = (q.size() == 1 ? ">" : ", ");
				cout << q.front() << dlim;
			}
			q.pop();
		}
	}
	return 0;
}