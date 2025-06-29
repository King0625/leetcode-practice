package leetcode

func lengthOfLongestSubstring(s string) int {
	byteMap := make(map[byte]bool)
	result, left, right := 0, 0, 0
	for i := 0; i < len(s); i++ {
		if _, ok := byteMap[s[i]]; !ok {
			byteMap[s[i]] = true
		} else {
			currLen := right - left
			result = max(result, currLen)
			for s[left] != s[right] {
				delete(byteMap, s[left])
				left++
			}
			left++
		}
		right++
	}

	result = max(result, right-left)
	return result
}
