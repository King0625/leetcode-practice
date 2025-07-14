package leetcode

var directions [4][2]int = [4][2]int{
	{0, 1}, {0, -1}, {1, 0}, {-1, 0},
}

func dfs(x, y int, board [][]byte) {
	row, col := len(board), len(board[0])
	board[x][y] = '*'
	for i := 0; i < 4; i++ {
		newX, newY := x+directions[i][0], y+directions[i][1]
		if newX >= 0 && newX < row && newY >= 0 && newY < col && board[newX][newY] == 'O' {
			dfs(newX, newY, board)
		}
	}
}

func solve(board [][]byte) {
	row, col := len(board), len(board[0])
	for i := 0; i < row; i++ {
		if board[i][0] == 'O' {
			dfs(i, 0, board)
		}
		if board[i][col-1] == 'O' {
			dfs(i, col-1, board)
		}
	}

	for j := 0; j < col; j++ {
		if board[0][j] == 'O' {
			dfs(0, j, board)
		}
		if board[row-1][j] == 'O' {
			dfs(row-1, j, board)
		}
	}

	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if board[i][j] == 'O' {
				board[i][j] = 'X'
			} else if board[i][j] == '*' {
				board[i][j] = 'O'
			}
		}
	}
}
