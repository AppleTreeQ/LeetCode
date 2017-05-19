package leetcode;

public class SudokuSolver {

	private boolean isComp = false;
	
	public void solveSudoku(char[][] board) {
		int i = 0, j = 0;
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) {
				if (board[i][j] == '.')
					break;
			}
			if (j < 9) {
				break;
			}
		}
		if (i == 9 && j == 9) {
			isComp = true;
			return;
		}
		for (char c = '1'; c <= '9'; c++) {
			if (isValid(board, i, j, c)) {
				board[i][j] = c;
				solveSudoku(board);
				if (isComp)
					return;
			}
		}
		board[i][j] = '.';
	}
	
	private boolean isValid(char[][] board, int m, int n, char c) {
		for (int i = 0; i < 9; i++) {
			if (i != m && board[i][n] == c)
				return false;
		}
		for (int j = 0; j < 9; j++) {
			if (j != n && board[m][j] == c)
				return false;
		}
		for (int i = m / 3 * 3; i < m / 3 * 3 + 3; i++) {
			for (int j = n / 3 * 3; j < n / 3 * 3 + 3; j++) {
				if (i != m && j != n && board[i][j] == c)
					return false;
			}
		}
		return true;
	}
}
