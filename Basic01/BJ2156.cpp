#include <iostream>
using namespace std;
const int MAX = 10000;
int arr[MAX + 1], dp[MAX + 1];

// dp[n] : n개의 포도주가 있을 때, 마실 수 있는 최대 포도주 양

// <기존과 달라진 점>
// 1.
// 점화식의 정의 수정
// 기존 : n번째 잔을 무조건 마실 때 maximum
// 신규 : n번째 잔까지의 maximum

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++) {
		// <순서>
		// 1. n번째 잔을 마시는 경우끼리 비교하여 max 산출
		// 2. 1의 max와 n번째 잔을 마시지 않는 경우를 비교
		dp[i] = max(max(dp[i - 2], dp[i - 3] + arr[i - 1]) + arr[i], dp[i - 1]);
	}

	cout << dp[n];
	return 0;
}
