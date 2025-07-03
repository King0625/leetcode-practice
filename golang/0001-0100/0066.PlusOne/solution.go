package leetcode

func plusOne(digits []int) []int {
	idx := len(digits) - 1

	for idx >= 0 {
		addByOne := digits[idx] + 1
		if addByOne == 10 {
			digits[idx] = 0
		} else {
			digits[idx]++
			break
		}

		idx--
	}

	if idx < 0 {
		digits = append([]int{1}, digits...)
	}

	return digits
}
