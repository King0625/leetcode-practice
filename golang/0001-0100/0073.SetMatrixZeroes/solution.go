package leetcode

func setZeroes(matrix [][]int)  {
	rows, cols := len(matrix), len(matrix[0])
	var rowToZero, colToZero []int
	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			if matrix[i][j] == 0 {
				rowToZero = append(rowToZero, i)
				colToZero = append(colToZero, j)
			}
		}
	}

	for _, x := range rowToZero {
		for i := 0; i < cols; i++ {
			matrix[x][i] = 0
		}
	}

	for _, y := range colToZero {
		for j := 0; j < rows; j++ {
			matrix[j][y] = 0
		}
	}
}

