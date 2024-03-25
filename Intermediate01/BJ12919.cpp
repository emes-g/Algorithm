#include <iostream>
#include <algorithm>
using namespace std;

// <문제 파악>
// S→T : O(2^50)이므로 시간 초과 (불가능)
// 따라서 T→S로 문제를 풀어야 함

// <가능한 경우>
// A...A → A연산
// A...B → 불가능
// B...A → A연산 OR B연산 (*)
// B...B → B연산

// 시간복잡도 : O(N^3) = O(N) * O(N^2)
// (N = len(T) - len(S))
// O(N) : O(reverse)
// O(N^2) : 특정 문자열의 길이에서 케이스 *은 오직 한 번만 일어남.
// 이 문제에서 문자열의 길이는 N이므로 케이스 *은 N번 일어날 것임. 
// → N * N

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
