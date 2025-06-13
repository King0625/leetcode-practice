package leetcode

func searchMatrix(matrix [][]int, target int) bool {
	rows := len(matrix)
	cols := len(matrix[0])

	possibleRow := -1
	for i := 0; i < rows; i++ {
		leftVal := matrix[i][0]
		rightVal := matrix[i][cols-1]

		if leftVal == target || rightVal == target {
			return true
		} else if leftVal > target {
			return false
		} else if leftVal < target && rightVal > target {
			possibleRow = i
			break
		}
	}

	if possibleRow == -1 {
		return false
	}

	leftIndex, rightIndex := 0, cols-1

	for leftIndex < rightIndex {
		mid := (leftIndex + rightIndex) / 2
		midVal := matrix[possibleRow][mid]

		if midVal > target {
			rightIndex--
		} else if midVal < target {
			leftIndex++
		} else {
			return true
		}
	}

	return false
}
