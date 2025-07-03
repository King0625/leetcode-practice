package leetcode

func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}
	var digits []int

	for x > 0 {
		digits = append(digits, x%10)
		x /= 10
	}

	left, right := 0, len(digits)-1

	for left < right {
		if digits[left] != digits[right] {
			return false
		}
		left++
		right--
	}

	return true
}
