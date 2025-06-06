package leetcode

import "unicode"

func isPalindrome(s string) bool {
	size := len(s)
	
	left, right := 0, size-1

	isAlphanumeric := func (r rune) bool {
		return unicode.IsLetter(r) || unicode.IsDigit(r)
	}

	for left < right {
		for !isAlphanumeric(rune(s[left])) && left < right {
			left++
		}

		for !isAlphanumeric(rune(s[right])) && left < right {
			right--
		}

		if unicode.ToLower(rune(s[left])) != unicode.ToLower(rune(s[right])) {
			return false
		} else {
			left++
			right--
		}
	}

	return true
}

