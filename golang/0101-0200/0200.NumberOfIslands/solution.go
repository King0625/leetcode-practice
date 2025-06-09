package leetcode

var direction = [][]int{
	{1, 0}, {0, 1}, {-1, 0}, {0, -1},
}

func bfs(row, col int, grid [][]byte) {
	rows := len(grid)
	cols := len(grid[0])

	grid[row][col] = byte('*')

	for i := 0; i < 4; i++ {
		newRow := row + direction[i][0]
		newCol := col + direction[i][1]

		if newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && rune(grid[newRow][newCol]) == '1' {
			bfs(newRow, newCol, grid)
		}
	}
}

func numIslands(grid [][]byte) int {
	var count int

	rows := len(grid)
	cols := len(grid[0])

	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			if rune(grid[i][j]) == '1' {
				count++
				bfs(i, j, grid)
			}
		}
	}

	return count
}

