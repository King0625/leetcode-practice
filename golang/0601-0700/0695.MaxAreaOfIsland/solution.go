package leetcodee

var directions = [4][2]int{
	{1, 0}, {0, 1}, {-1, 0}, {0, -1},
}

func maxAreaOfIsland(grid [][]int) int {
	result := 0
	row := len(grid)
	col := len(grid[0])

	var dfs func(int, int) int

	dfs = func(x, y int) int {
		if x < 0 || y < 0 || x >= row || y >= col || grid[x][y] != 1 {
			return 0
		}

		area := 1
		grid[x][y] = 2

		for i := 0; i < 4; i++ {
			newX := x + directions[i][0]
			newY := y + directions[i][1]

			area += dfs(newX, newY)
		}

		return area
	}

	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if grid[i][j] == 1 {
				area := dfs(i, j)
				result = max(result, area)
			}
		}
	}

	return result
}
