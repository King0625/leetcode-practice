package leetcode

var directions [4][2]int = [4][2]int{
	{1, 0}, {-1, 0}, {0, 1}, {0, -1},
}

func dfs(matrix [][]int, row, col, x, y int, dp [][]int) int {
	if dp[x][y] != 0 {
		return dp[x][y]
	}

	maxVal := 1

	for i := 0; i < 4; i++ {
		newX := x + directions[i][0]
		newY := y + directions[i][1]

		if newX < 0 || newY < 0 || newX >= row || newY >= col || matrix[newX][newY] <= matrix[x][y] {
			continue
		}

		length := 1 + dfs(matrix, row, col, newX, newY, dp)
		maxVal = max(maxVal, length)
	}

	dp[x][y] = maxVal
	return maxVal

}
func longestIncreasingPath(matrix [][]int) int {
	row, col := len(matrix), len(matrix[0])

	dp := make([][]int, row)
	for i := 0; i < row; i++ {
		dp[i] = make([]int, col)
	}
	result := 1
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			length := dfs(matrix, row, col, i, j, dp)
			result = max(result, length)
		}
	}

	return result
}

