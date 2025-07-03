package leetcode

func productExceptSelf(nums []int) []int {
	var zeroCount int

	productWithoutZero := 1
	for _, num := range nums {
		if num == 0 {
			zeroCount++
		} else {
			productWithoutZero *= num
		}
	}

	result := make([]int, len(nums))

	for i, num := range nums {
		if num != 0 && zeroCount == 0 {
			result[i] = productWithoutZero / num
		} else if num == 0 && zeroCount == 1 {
			result[i] = productWithoutZero
		}
	}

	return result
}
