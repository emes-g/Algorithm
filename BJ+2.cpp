#include <iostream>
#include <algorithm>
using namespace std;
const int n = 5;
int a[n] = { 4,2,3,5,1 };

// quick_sort
// 1. 시간 복잡도
// 	평균 O(n * logn)
// 	최악 O(n^2)

int partition(int start, int end) {
	int pivotIdx = (start + end) / 2;
	int pivotValue = a[pivotIdx];
	swap(a[pivotIdx], a[end]);

	int j = start;	// 반환할 값 (pivot)
	for (int i = start; i < end; i++) {
		if (a[i] < pivotValue) {	// 부등호만 바꿔주면 내림차순
			swap(a[i], a[j++]);
		}
	}
	swap(a[j], a[end]);
	return j;	// pivot
}

void quick_sort(int start, int end) {
	if (start < end) {
		// 피벗을 기준으로
		// 피벗 앞에는 피벗보다 작은 값만
		// 피벗 뒤에는 피벗보다 큰 값만 존재
		int pivot = partition(start, end);
		quick_sort(start, pivot - 1);
		quick_sort(pivot + 1, end);
	}
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
	quick_sort(0, n - 1);
	print("\n정렬 후: ");
}
