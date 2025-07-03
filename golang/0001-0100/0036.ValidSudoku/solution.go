package leetcode

import "unicode"

func check(row, col int, board [][]byte) bool {
	for i := 0; i < 9; i++ {
		if board[row][i] == board[row][col] && i != col {
			return false
		}
	}

	for j := 0; j < 9; j++ {
		if board[j][col] == board[row][col] && j != row {
			return false
		}
	}

	gridRow := row / 3
	gridCol := col / 3

	for i := gridRow * 3; i < gridRow*3+3; i++ {
		for j := gridCol * 3; j < gridCol*3+3; j++ {
			if board[i][j] == board[row][col] && i != row && j != col {
				return false
			}
		}
	}

	return true
}

func isValidSudoku(board [][]byte) bool {
	for row := 0; row < 9; row++ {
		for col := 0; col < 9; col++ {
			if !unicode.IsDigit(rune(board[row][col])) {
				continue
			}
			if !check(row, col, board) {
				return false
			}
		}
	}

	return true
}
