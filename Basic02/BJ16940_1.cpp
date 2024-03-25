#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
const int MAX = 100001;
vector<vector<int>> a;
queue<int> input;	// vector<int> input;
bool check[MAX];

// <참고 사이트>
// 입력 받은 순서대로 알고리즘을 작성하고 싶어서,
// 몇 시간 동안 고민하고 여러 사이트를 돌아다닌 끝에 발견!
// https://transferhwang.tistory.com/397

bool bfs(int start) {
	queue<int> q;
	q.push(start);	// start == 1
	check[start] = true;

	while (!q.empty()) {
		set<int> s;
		int x = q.front();
		q.pop();
		for (int next : a[x]) {
			if (!check[next]) {
				s.insert(next);
				check[next] = true;
			}
		}

		for (auto it = s.begin(); it != s.end(); it++) {
			int num = input.front();
			input.pop();
			if (s.find(num) == s.end()) {
				return false;
			}
			else {
				q.push(num);
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n;
	cin >> n;
	a.assign(n + 1, vector<int>());
	for (int i = 0; i < n - 1; i++) {
		int from, to;
		cin >> from >> to;
		a[from].push_back(to);
		a[to].push_back(from);
	}
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		input.push(num);
	}

	// 2. solve (bfs + set)
	int start = input.front();
	input.pop();
	if (start != 1) {
		cout << 0;
		return 0;
	}
	if (bfs(start)) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}