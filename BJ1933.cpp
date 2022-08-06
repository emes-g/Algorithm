#include <iostream>
#include <vector>
#include <tuple>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

// <알고리즘>
// 1. 건물의 시작, 끝점마다 체크해줘야 함 (건물의 높이가 변했는지, 변했다면 올라갔는지 내려갔는지)
// → (현재 점, 높이, 반대편 점, 상태)를 입력받을 것임.
// 2. 현재 점을 기준으로 오름차순 정렬하여 볼 것임 (for using line sweeping)
// 3. 시작점이면 sky에 넣어주고, 끝점이면 해당 건물을 sky에서 삭제
// 4. sky의 최댓값 갱신 (후술)
// 5. 정답 출력 (후술)

// <포인트>
// 1. sky를 pq가 아니라 set으로 지정한 이유?
// → 정렬함에 있어서는 pq도 상관없으나 find 기능을 이용하기 위해서임.
// 2. sky의 의미?
// → 현재 점이 시작점일 때, (끝점, 높이)를 저장하여 현재 어떤 건물들을 지나고 있는지 확인 가능
// 3. pair, tuple의 정렬?
// → 사용자 정의 자료형이 아니라면 (int와 같은 기본 자료형이라면) 별도의 정렬 기준이 필요하지 않음

// <반성>
// 1. 앞으로도 내가 유용하게 사용할 것 같은 코드는 이해하려고 노력해보자
// (멘탈 나갔다고 딴 코드 계속 찾지는 말기, 적당히 찾되)

// <좋은 예제>
// 2
// 1 1 2
// 2 1 3
// answer : 1 1 3 0

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n;
	cin >> n;
	vector<tuple<int, int, int, int>> a;
	for (int i = 0; i < n; i++) {
		int x, h, y;
		cin >> x >> h >> y;
		a.push_back({ x,h,y,0 });
		a.push_back({ y,h,x,1 });
	}
	sort(a.begin(), a.end());

	// 2. solve (line sweeping)
	set<pii, greater<pii>> sky;
	map<int, int> ans;
	sky.insert({ 0,0 });	// 지평선이라면 언제나 높이가 0인 지점은 지나고 있으므로 (끝점은 어떤 값으로 해도 무관)
	int prev = -1;	// a[i-1]의 최대 높이
	for (int i = 0; i < 2 * n; i++) {
		int x, h, y, s;
		tie(x, h, y, s) = a[i];

		// 1. push or pop
		if (s == 0) {	// 시작점이라면 push
			sky.insert({ h,y });
		}
		else {	// 끝점이라면 pop
			sky.erase({ h,x });
		}

		// 2. 최댓값 갱신
		int maxH = sky.begin()->first;

		// 3. 유의미한 연산 발생했다면 (현재 점에서 스카이라인의 높이가 변화한 상황이라면)
		if (maxH != prev) {
			prev = maxH;
			if (s == 0) {	// 스카이라인이 높아진 상황
				ans[x] = max(ans[x], maxH);
			}
			else {	// 스카이라인이 낮아진 상황
				if (ans.count(x) == 0) {	// 현재 좌표에 처음 도달한 상황
					ans[x] = maxH;
				}
				else {
					ans[x] = min(ans[x], maxH);
				}
			}
		}
	}

	// 3. output
	prev = -1;
	for (auto it = ans.begin(); it != ans.end(); it++) {
		if (prev != it->second) {	// 이전과 동일한 높이라면 출력하면 안 된다.
			prev = it->second;
			cout << it->first << ' ' << it->second << ' ';
		}
	}
}