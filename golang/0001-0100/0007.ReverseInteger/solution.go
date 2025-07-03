package leetcode

import "math"

func reverse(x int) int {
	isNegative := false

	num := x
	if num < 0 {
		isNegative = true
		num *= -1
	}

	var digits []int

	for num > 0 {
		digits = append(digits, num%10)
		num /= 10
	}

	digitLen := len(digits)
	power := digitLen - 1

	result := 0
	for power >= 0 {
		index := digitLen - power - 1
		if digits[index] != 0 {
			result += digits[index] * int(math.Pow10(power))
		}

		power--
	}

	if isNegative {
		result *= -1
	}

	if result > math.MaxInt32 || result < math.MinInt32 {
		return 0
	}

	return result
}
