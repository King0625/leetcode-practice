package leetcode

import "math"

func minPathSum(grid [][]int) int {
	row := len(grid)
	col := len(grid[0])

	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if i == 0 && j != 0 {
				grid[i][j] += grid[i][j-1]
			} else if j == 0 && i != 0 {
				grid[i][j] += grid[i-1][j]
			} else if i != 0 && j != 0 {
				topVal := grid[i-1][j]
				leftVal := grid[i][j-1]
				grid[i][j] += int(math.Min(float64(topVal), float64(leftVal)))
			}
		}
	}

	return grid[row-1][col-1]
}
