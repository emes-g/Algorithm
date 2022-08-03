#include <iostream>
#include <algorithm>
using namespace std;

// <문제 파악>
// S→T : O(2^50)이므로 시간 초과 (불가능)
// 따라서 T→S로 문제를 풀어야 함

// T→S인 경우 시간복잡도는 N^2 * O(N)인데,
// 핵심은 S→T가 불가능하다는 사실임

string cut(string t) {
	t.pop_back();
	return t;
}

string rev(string t) {
	reverse(t.begin(), t.end());
	return t;
}

bool go(string& s, string t) {
	if (s == t) {	// 정답인 경우
		return true;
	}
	else if (s.length() >= t.length()) {	// 불가능한 경우
		return false;
	}
	
	if (t.back() == 'A' && go(s, cut(t))) {	// A연산
		return true;
	}
	if (t.front() == 'B' && go(s, cut(rev(t)))) {	// B연산
		return true;
	}
	return false;
}

int main() {
	string s, t;
	cin >> s >> t;
	cout << go(s, t);
}