#include <iostream>
#include <queue>
#include <set>
using namespace std;
long long s, t;

// <주의 사항>
// s와 t의 범위가 10억 이하이므로 check를 통해 문제를 해결할 수 없다.
// → set을 이용해야 한다.

long long calc(long long x, int op) {
	switch (op) {
	case 0:
		return x * x;
	case 1:
		return x * 2;
	}
}

string bfs() {
	queue<pair<long long, string>> q;
	set<long long> num;	// 나온 숫자
	q.push({ s,"" });
	num.insert(s);
	while (!q.empty()) {
		long long x = q.front().first;
		string str = q.front().second;
		q.pop();
		if (x == t) {	// 답을 찾은 경우
			return str;
		}
		else if (str != "" && x > t) {	// 백트래킹 (계속해도 답을 찾을 수 없으므로 가지를 쳐 낸다)
			continue;
		}
		for (int k = 0; k < 2; k++) {
			long long res = calc(x, k);
			char ch = (k == 0 ? '*' : '+');
			if (num.find(res) == num.end()) {	// 아직 해당 숫자를 구현한 적이 없다면
				q.push({ res, str + ch });
				num.insert(res);
			}
		}
		if (str.size() == 0) {
			q.push({ 0,"-" });
			q.push({ 1,"/" });
		}
	}
	return "-1";
}

int main() {
	cin >> s >> t;
	if (s == t) {
		cout << 0;
		return 0;
	}
	cout << bfs();
}