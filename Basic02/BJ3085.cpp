#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char color[4] = { 'C', 'P', 'Z', 'Y' };

// 시간복잡도 : O(N^4)
// 범위 : 3 ≤ N ≤ 50

// <기존 코드와의 차별점>
// 상하좌우 전부 확인하던 기존 코드와 달리,
// 개선된 코드는 우측과 아래만 확인한다.

// 하지만 간과한 점이 두 수를 스왑하면 바뀌는 줄은 2개가 아니라 3개라는 것이다.
// 기존 코드는 상하좌우를 모두 판별하므로 의도대로 작동하지만,
// 개선된 코드는 우측과 아래만을 확인하므로 확인되지 않는 줄이 발생하게 된다.

// 따라서 바뀐 세 줄을 모두 확인할 수 있도록 알고리즘을 수정했다.

int checkRow(vector<vector<char>>& board, int n, int row) {
	int res = 0;

	for (int i = 0; i < 4; i++) {
		int cur = 0;
		for (int j = 1; j <= n; j++) {
			if (color[i] == board[row][j]) {
				cur++;
				res = max(res, cur);
			}
			else {
				cur = 0;
			}
		}
	}
	return res;
}

int checkCol(vector<vector<char>>& board, int n, int col) {
	int res = 0;

	for (int i = 0; i < 4; i++) {
		int cur = 0;
		for (int j = 1; j <= n; j++) {
			if (color[i] == board[j][col]) {
				cur++;
				res = max(res, cur);
			}
			else {
				cur = 0;
			}
		}
	}
	return res;
}

int main() {
	// 1. input
	int n, ans = 0;
	cin >> n;
	vector<vector<char>> board(n + 2, vector<char>(n + 2, '0'));	// char board[n+2][n+2]
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= n; j++) {
			board[i][j] = str[j - 1];
		}
	}

	// 2. solve (brute force)
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j + 1] != '0') {	// 오른쪽과 비교
				swap(board[i][j], board[i][j + 1]);
				ans = max(ans, checkRow(board, n, i));
				ans = max(ans, checkCol(board, n, j));
				ans = max(ans, checkCol(board, n, j + 1));
				swap(board[i][j], board[i][j + 1]);
			}
			if (board[i + 1][j] != '0') {	// 아래와 비교
				swap(board[i][j], board[i + 1][j]);
				ans = max(ans, checkRow(board, n, i));
				ans = max(ans, checkRow(board, n, i + 1));
				ans = max(ans, checkCol(board, n, j));
				swap(board[i][j], board[i + 1][j]);
			}
			if (ans == n) {
				cout << n;
				return 0;
			}
		}
	}

	// 3. output
	cout << ans;
	return 0;
}
