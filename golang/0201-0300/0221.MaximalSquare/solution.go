package main

import "fmt"

func maximalSquare(matrix [][]byte) int {
	row, col := len(matrix), len(matrix[0])
	memoi := make([][]int, row)

	for i := 0; i < row; i++ {
		memoi[i] = make([]int, col)
		for j := 0; j < col; j++ {
			if i == 0 && j == 0 {
				memoi[i][j] = int(matrix[i][j])
			} else if i == 0 && j != 0 {
				memoi[i][j] = memoi[i][j-1] + int(matrix[i][j])
			} else if i != 0 && j == 0 {
				memoi[i][j] = memoi[i-1][j] + int(matrix[i][j])
			}
		}
	}

	fmt.Println(memoi)
	return 0
}

func main() {
	matrix := [][]byte{
		{1,0,1,0,0},
		{1,0,1,1,1},
		{1,1,1,1,1},
		{1,0,0,1,0},
	}

	fmt.Println(maximalSquare(matrix))
}
