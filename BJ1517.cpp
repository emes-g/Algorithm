#include <iostream>
#include <vector>
using namespace std;
vector<int> a, b;
long long ans;

// <문제 파악>
// Bubble Sort에서 swap의 발생 횟수?
// → 수열에서 inversion이 발생한 횟수
// → 수열의 inversion 개수를 세는 문제
// → 위치상 앞에 있으면서 값이 더 큰 것의 개수가 몇 개?

void merge(int start, int end) {
	int mid = (start + end) / 2;
	int i = start, j = mid + 1, k = 0;
	while (i <= mid && j <= end) {
		if (a[i] <= a[j]) {	// 같을 때도 해당 경우에 포함하여, inversion 횟수가 무분별하게 증가하지 않도록 한다.
			b[k++] = a[i++];
		}
		else {
			b[k++] = a[j++];
			// 합병 시, 앞 배열의 남은 숫자 개수를 더해준다.
			// 왜? 해당 숫자들보다는 앞으로 가야하니까
			ans += (mid - i + 1);
		}
	}
	while (i <= mid) {
		b[k++] = a[i++];
	}
	while (j <= end) {
		b[k++] = a[j++];
	}
	for (int i = start; i <= end; i++) {
		a[i] = b[i - start];
	}
}

void merge_sort(int start, int end) {
	if (start == end) {
		return;
	}
	int mid = (start + end) / 2;
	merge_sort(start, mid);
	merge_sort(mid + 1, end);
	merge(start, end);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. input
	int n;
	cin >> n;
	a.assign(n, 0);
	b.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	// 2. solve
	merge_sort(0, n - 1);

	// 3. output
	cout << ans;
}
