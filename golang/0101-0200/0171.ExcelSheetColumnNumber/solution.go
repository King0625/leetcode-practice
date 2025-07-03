package leetcode

import "math"

func titleToNumber(columnTitle string) int {
	result := 0

	power := len(columnTitle) - 1
	for _, letter := range columnTitle {
		result += (int(letter-'A') + 1) * int(math.Pow(26.0, float64(power)))
		power--
	}

	return result
}
