#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 1001;
int a[MAX][MAX];

// void* cstring::memset(void* ptr, int value, size_t num)
// 메모리의 내용을 원하는 길이만큼 특정 값으로 세팅하는 함수
// ptr   : 세팅할 메모리의 시작 주소
// value : 세팅할 값
// num   : 길이 (바이트 단위)
// ㄴ 보통 sizeof(ptr)로 많이 사용한다.

void bfs(int s) {
	queue<pair<int, int>> q;
	q.push({ 1,0 });
	a[1][0] = 0;
	while (!q.empty()) {
		int d = q.front().first;	// d : display
		int c = q.front().second;	// c : clip
		q.pop();
		
		// 화면에 이모티콘 s개가 만들어진 첫 순간
		if (d == s) {
			cout << a[d][c];
			break;
		}

		// 화면 전부 -> 클립보드에 저장
		if (a[d][d] == -1) {
			a[d][d] = a[d][c] + 1;
			q.push({ d,d });
		}
		
		// 클립보드 전부 -> 화면에 붙여넣기
		if (d + c < MAX && a[d + c][c] == -1) {
			a[d + c][c] = a[d][c] + 1;
			q.push({ d + c,c });
		}

		// 화면에 있는 이모티콘 하나를 삭제
		if (d - 1 >= 0 && a[d - 1][c] == -1) {
			a[d - 1][c] = a[d][c] + 1;
			q.push({ d - 1,c });
		}
	}
}

int main() {
	int s;
	cin >> s;
	memset(a, -1, sizeof(a));
	bfs(s);
	return 0;
}