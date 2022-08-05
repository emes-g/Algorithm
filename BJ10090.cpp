#include <iostream>
#include <vector>
using namespace std;
vector<int> a, b;
long long ans;

// <문제 파악>
// counting inversion : inversion 횟수를 세는 문제
// → 버블 소트 문제(1517)와 동일

void merge(int start, int end) {
	int mid = (start + end) / 2;
	int i = start, j = mid + 1, k = 0;
	while (i <= mid && j <= end) {
		if (a[i] <= a[j]) {
			b[k++] = a[i++];
		}
		else {
			b[k++] = a[j++];
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