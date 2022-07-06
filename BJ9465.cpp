#include <iostream>
#include <vector>
using namespace std;

// dp[k][n] : 2*n 스티커 중에서 가능한 한 가장 큰 점수의 합
// 단, 정수 k에 대응하여 n열의 스티커 선택이 결정된다.
// k : 0 -> 위 스티커 선택
// k : 1 -> 아래 스티커 선택
// k : 2 -> 해당 열에서 스티커 선택 X

// <기존과 달라진 점>
// 어차피 스티커 배열은 일회용으로 사용할 것이기 때문에 
// 애초에 값을 dp 배열에 저장해 놓음으로써, 메모리적 이득을 취했다.

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		vector<vector<int>> dp(3, vector<int>(n));
		for (int i = 0; i < n; i++) {
			cin >> dp[0][i];
		}
		for (int i = 0; i < n; i++) {
			cin >> dp[1][i];
		}

		for (size_t i = 1; i < n; i++) {
			dp[0][i] += max(dp[1][i - 1], dp[2][i - 1]);
			dp[1][i] += max(dp[0][i - 1], dp[2][i - 1]);
			dp[2][i] = max(max(dp[0][i - 1], dp[1][i - 1]), dp[2][i - 1]);
		}

		for (int i = 0; i < 3; i++) {
			if (ans < dp[i][n - 1]) {
				ans = dp[i][n - 1];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
