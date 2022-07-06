#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000;
int dp[3][MAX];	// 배열을 전역으로 선언하지 않으면 프로그램이 비정상적으로 종료한다.

// dp[k][n] : 2*n 스티커 중에서 가능한 한 가장 큰 점수의 합
// 단, 정수 k에 대응하여 n열의 스티커 선택이 결정된다.
// k : 0 -> 위 스티커 선택
// k : 1 -> 아래 스티커 선택
// k : 2 -> 해당 열에서 스티커 선택 X

// <기존과 달라진 점>
// 1.
// 어차피 스티커 배열은 일회용으로 사용할 것이기 때문에 
// 애초에 값을 dp 배열에 저장해 놓음으로써, 메모리적 이득을 취했다.

// 2.
// int의 경우, 2차원 vector보다 2차원 배열이 속도나 메모리적인 측면에서 이득이다.
// 단, vector와 달리 2차원 배열은 크기를 동적으로 생성할 수 없고 초기화가 불편하다는 단점이 있다.
// 상황에 맞게 골라 쓰자.
// 2차원 vector : 3908kb / 88ms
// 2차원 배열 : 3192kb / 84ms

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		for (int i = 0; i < 3; i++) {
			fill_n(dp[i], MAX, 0);
		}
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
