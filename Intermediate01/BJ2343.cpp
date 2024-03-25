#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> a;

bool good(int mid) {
	int cnt = 1, sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > mid) {	// 현재 블루레이의 크기로는 한 개의 레슨도 담지 못하는 경우
			return false;
		}
		else if (sum + a[i] <= mid) {
			sum += a[i];
		}
		else {
			cnt++;
			sum = a[i];
		}
	}
	return cnt <= m;
}

int binary_search(int left, int right) {
	while (left <= right) {
		int mid = (left + right) / 2;
		if (good(mid)) {	// 현재 블루레이 크기로 모든 레슨을 담을 수 있는 경우
			right = mid - 1;	// 블루레이 크기를 최소로 하기 위해 축소
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	a.resize(n);
	int right = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		right += a[i];
	}
	cout << binary_search(1, right);
}
