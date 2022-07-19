#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 100001;
int student[MAX], visit[MAX];
bool finish[MAX];
int order, ans;

// <cycle detecion>
// 일반적으로 cycle의 '개수' 혹은 '존재 여부'를 구하지만,
// 이 문제는 cycle의 '크기'를 알아내는 것이 핵심이다.

// 기존의 check 기능을 visit가 담당하는데, 방문 여부 대신 방문 순서를 기록한다.
// 왜? 
// 사이클 발견 시점의 방문 순서에서 사이클 시작점의 방문 순서를 빼면 사이클의 크기가 나오기 때문이다.

void init() {
	order = 1;
	memset(visit, 0, sizeof(visit));
	memset(finish, false, sizeof(finish));
}

void dfs(int x) {
	if (!visit[x]) {
		visit[x] = order++;
		dfs(student[x]);
		finish[x] = true;
	}
	else if (!finish[x]) {	// cycle detection
		ans -= (order - visit[x]);
		return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		init();

		// 1. input
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> student[i];
		}

		// 2. solve (dfs - cycle detection)
		ans = n;
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) {
				dfs(i);
			}
		}

		// 3. output
		cout << ans << '\n';
	}
	return 0;
}
