#include <iostream>
using namespace std;
const int n = 5;
int a[n] = { 4,2,5,1,3 }, b[n];

// merge_sort
// 시간 복잡도 : O(n * logn)
// ∴ 합병 → logn * O(n)

void merge(int start, int end) {	// 기저 : two pointer
	int mid = (start + end) / 2;
	int i = start, j = mid + 1, k = 0;
	while (i <= mid && j <= end) {
		if (a[i] <= a[j]) {	// 부등호만 바꿔주면 내림차순
			b[k++] = a[i++];
		}
		else {
			b[k++] = a[j++];
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

void sort(int start, int end) {
	if (start == end) {
		return;
	}
	int mid = (start + end) / 2;
	sort(start, mid);
	sort(mid + 1, end);
	merge(start, end);
}

void print(string comment) {
	cout << comment;
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	print("정렬 전: ");
	sort(0, n - 1);
	print("\n정렬 후: ");
}
