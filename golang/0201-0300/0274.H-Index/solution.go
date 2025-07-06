package leetcode

import "slices"

func hIndex(citations []int) int {
	slices.Sort(citations)
	size := len(citations)
	result := 0
	for i := 0; i < size; i++ {
		citation := citations[i]
		count := size - i
		if citation >= count {
			result = max(result, count)
		}
	}

	return result
}
