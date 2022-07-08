#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char color[4] = { 'C', 'P', 'Z', 'Y' };

// 시간복잡도 : O(N^4)
// 범위 : 3 ≤ N ≤ 50

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
				swap(board[i][j], board[i][j + 1]);
			}
			if (board[i + 1][j] != '0') {	// 아래와 비교
				swap(board[i][j], board[i + 1][j]);
				ans = max(ans, checkRow(board, n, i));
				ans = max(ans, checkCol(board, n, j));
				swap(board[i][j], board[i + 1][j]);
			}
			if (board[i][j - 1] != '0') {	// 왼쪽과 비교
				swap(board[i][j], board[i][j - 1]);
				ans = max(ans, checkRow(board, n, i));
				ans = max(ans, checkCol(board, n, j));
				swap(board[i][j], board[i][j - 1]);
			}
			if (board[i - 1][j] != '0') {	// 위와 비교
				swap(board[i][j], board[i - 1][j]);
				ans = max(ans, checkRow(board, n, i));
				ans = max(ans, checkCol(board, n, j));
				swap(board[i][j], board[i - 1][j]);
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
