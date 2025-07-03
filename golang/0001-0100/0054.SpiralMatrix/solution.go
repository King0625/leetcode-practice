package leetcode

func spiralOrder(matrix [][]int) []int {
	row := len(matrix)
	col := len(matrix[0])

	var result []int

	rounds := 0
	count := 0
	total := row * col
	for {
		if count < total {
			for i := rounds; i < col-rounds; i++ {
				result = append(result, matrix[rounds][i])
				count++
			}
		}

		if count < total {
			for j := rounds + 1; j < row-rounds; j++ {
				result = append(result, matrix[j][col-rounds-1])
				count++
			}
		}

		if count < total {
			for k := col - rounds - 2; k >= rounds; k-- {
				result = append(result, matrix[row-rounds-1][k])
				count++
			}
		}

		if count < total {
			for m := row - rounds - 2; m >= rounds+1; m-- {
				result = append(result, matrix[m][rounds])
				count++
			}
		}

		if count == row*col {
			break
		}
		rounds++
	}

	return result
}
