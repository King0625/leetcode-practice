package leetcode

import "slices"

func rotate(matrix [][]int) {
	width := len(matrix)
	for i := 0; i < width; i++ {
		for j := i; j < width; j++ {
			matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
		}
	}

	for i := range width {
		slices.Reverse(matrix[i])
	}
}
