package leetcode

func longestIncreasingPath(matrix [][]int) int {
	row, col := len(matrix), len(matrix[0])
	result := 0

	var dfs func(int, int, int, int)
	dfs = func(x, y, prev, count int) {
		if x > row-1 || x < 0 || y > col-1 || y < 0 {
			result = max(result, count)
			return
		}
		if matrix[x][y] == -1 {
			result = max(result, count)
			return
		}
		if matrix[x][y] <= prev {
			result = max(result, count)
			return
		}

		count++
		temp := matrix[x][y]
		matrix[x][y] = -1
		dfs(x+1, y, temp, count)
		dfs(x-1, y, temp, count)
		dfs(x, y-1, temp, count)
		dfs(x, y+1, temp, count)
		matrix[x][y] = temp
	}

	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			dfs(i, j, -2, 0)
		}
	}

	return result
}
