#include <iostream>
using namespace std;
int a[10000];

bool next_permutation(int n) {
	// 1. 내림차순을 만족하지 못하는 수 a[i-1]을 찾는다.
	for (int i = n - 1; i >= 1; i--) {
		if (a[i - 1] < a[i]) {
			// 2. a[i-1]보다 큰 수 중 가장 작은 수 a[j-1]을 찾는다.
			int j = i;
			while (j < n && a[i - 1] <= a[j]) {	
				j++;
			}
			
			// 3. 위에서 구한 두 수를 swap한다.
			swap(a[i - 1], a[j - 1]);	
			
			// 4. a[i-1] 뒤에 존재하는 부분수열을 내림차순에서 오름차순으로 변경한다.
			j = n - 1;
			while (i < j) {	
				swap(a[i++], a[j--]);
			}
			return true;
		}
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (next_permutation(n)) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
	}
	else {
		cout << -1;
	}
}
