package main

func uniquePathsWithObstacles(obstacleGrid [][]int) int {
	row := len(obstacleGrid)
	col := len(obstacleGrid[0])
	if obstacleGrid[0][0] == 1 {
		return 0
	}
	obstacleGrid[0][0] = 1

	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if !(i == 0 && j == 0) && obstacleGrid[i][j] == 1 {
				obstacleGrid[i][j] = 0
				continue
			}

			if i == 0 && j > 0 {
				obstacleGrid[i][j] = obstacleGrid[i][j-1]
			} else if i > 0 && j == 0 {
				obstacleGrid[i][j] = obstacleGrid[i-1][j]
			} else if i > 0 && j > 0 {
				obstacleGrid[i][j] = obstacleGrid[i][j-1] + obstacleGrid[i-1][j]
			}
		}
	}

	return obstacleGrid[row-1][col-1]
}
