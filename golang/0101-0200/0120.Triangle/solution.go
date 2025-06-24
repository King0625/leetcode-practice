package leetcode

func minimumTotal(triangle [][]int) int {
	height := len(triangle)

	for i := 1; i < height; i++ {
		for j := 0; j < len(triangle[i]); j++ {
			current := triangle[i][j]
			if j == 0 {
				triangle[i][j] += triangle[i-1][j]
			} else if j == len(triangle[i])-1 {
				triangle[i][j] += triangle[i-1][j-1]
			} else {
				sum1 := current + triangle[i-1][j-1]
				sum2 := current + triangle[i-1][j]
				triangle[i][j] = min(sum1, sum2)
			}
		}
	}

	result := triangle[height-1][0]

	for i := 1; i < len(triangle[height-1]); i++ {
		fmt.Println(triangle[height-1][i])
		if result > triangle[height-1][i] {
			result = triangle[height-1][i]
		}
	}

	return result
}
