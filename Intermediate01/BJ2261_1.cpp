#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 800000000;
typedef pair<int, int> pii;
vector<pii> a;

// <변수 설명>
// dl	왼쪽에서 가장 가까운 두 점의 거리의 제곱
// dr	오른쪽에서 가장 가까운 두 점의 거리의 제곱
// d	전체에서 가장 가까운 두 점의 거리의 제곱
// in_area	거리를 확인해 볼 가치가 있는 점들을 담은 벡터

// <알고리즘>
// d = min(dl, dr, dist(point_in_left && point_in_right))
// 1. dl, dr은 분할 정복으로 자연스럽게 구하고, d를 min(dl,dr)로 갱신한다.
// 2. dist(point_in_left && point_in_right)는 다음의 과정으로 구한다.
//	(1) 현재 중심에서 x좌표의 거리가 d미만인 애들을 '후보'로 지정하여 in_area에 넣는다.
//	(2) in_area에 있는 두 점을 골라 y좌표 간 거리가 d미만이라면 d를 갱신한다. 
//		→ d = min(d, dist(해당 두 점))
//		(2)를 진행하기에 앞서, in_area를 y좌표 순으로 정렬하여 거리가 d이상인 점들을 모두 확인하지 않도록 처리해야 한다.

// 해당 문제는 line sweeping으로도 충분히 가능할 것 같다.
// line sweeping : 정렬된 요소들을 차례차례 단 한 번만 방문하여 정답이 나올 수 있도록 구현하는 방식

int dist(pii x, pii y) {
	return pow(x.first - y.first, 2) + pow(x.second - y.second, 2);
}

int closest(int start, int end) {
	int d = MAX;
	int n = end - start + 1;	// 요소 개수
	if (n <= 3) {
		for (int i = start; i < end; i++) {
			for (int j = i + 1; j <= end; j++) {
				d = min(d, dist(a[i], a[j]));
			}
		}
		return d;
	}
	int mid = (start + end) / 2;
	int dl = closest(start, mid - 1);
	int dr = closest(mid + 1, end);
	d = min(dl, dr);

	// 1. 현재 중심에서 x좌표의 거리가 d미만인 애들을 '후보'로 지정하여 in_area에 넣는다.
	vector<pii> in_area;
	in_area.push_back(a[mid]);
	for (int i = mid - 1; i >= start; i--) {
		int gap = pow(a[mid].first - a[i].first, 2);
		if (gap >= d) {
			break;
		}
		in_area.push_back(a[i]);
	}
	for (int i = mid + 1; i <= end; i++) {
		int gap = pow(a[mid].first - a[i].first, 2);
		if (gap >= d) {
			break;
		}
		in_area.push_back(a[i]);
	}

	// 2. in_area에 있는 두 점을 골라 y좌표 간 거리가 d 미만이라면 d를 갱신한다. 
	sort(in_area.begin(), in_area.end(), [](auto x, auto y) {	// y좌표순 정렬
		return x.second > y.second;
		});

	for (int i = 0; i < in_area.size() - 1; i++) {
		for (int j = i + 1; j < in_area.size(); j++) {
			int gap = pow(in_area[i].second - in_area[j].second, 2);
			if (gap >= d) {	// gap == d인 순간을 포함하면, 시간 복잡도가 기하급수적으로 증가한다.
				break;
			}
			d = min(d, dist(in_area[i], in_area[j]));
		}
	}
	return d;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end());	// x좌표순 정렬
	cout << closest(0, n - 1);
}