package leetcode

type Rectangle struct {
	index  int
	height int
}

func largestRectangleArea(heights []int) int {
	var result int
	var stack []Rectangle

	for i, height := range heights {
		prevIndex := i
		for len(stack) > 0 && stack[len(stack)-1].height > height {
			calcHeight := stack[len(stack)-1].height * (i - stack[len(stack)-1].index)
			result = max(result, calcHeight)
			prevIndex = stack[len(stack)-1].index

			stack = stack[:len(stack)-1]
		}
		stack = append(stack, Rectangle{prevIndex, height})
	}

	for _, val := range stack {
		area := val.height * (len(heights) - val.index)
		result = max(result, area)
	}

	return result
}
