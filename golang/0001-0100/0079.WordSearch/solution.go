package leetcode

func exist(board [][]byte, word string) bool {
	row, col := len(board), len(board[0])

	var dfs func(int, int, int) bool
	dfs = func(x, y, idx int) bool {
		findByte := word[idx]
		if x < 0 || x >= row || y < 0 || y >= col {
			return false
		}

		if board[x][y] != findByte {
			return false
		}

		if idx == len(word)-1 {
			return true
		}

		temp := board[x][y]
		board[x][y] = '*'
		found := dfs(x+1, y, idx+1) ||
			dfs(x, y+1, idx+1) ||
			dfs(x-1, y, idx+1) ||
			dfs(x, y-1, idx+1)
		board[x][y] = temp

		return found
	}

	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if dfs(i, j, 0) {
				return true
			}
		}
	}

	return false
}

