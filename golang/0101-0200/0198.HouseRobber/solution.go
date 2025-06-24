package leetcode

func rob(nums []int) int {
	memoization := make([]int, len(nums))

	result := nums[0]
	for i, num := range nums {
		if i < 2 {
			memoization[i] = num
			result = max(result, memoization[i])
		} else {
			incr := 0
			for i-2-incr >= 0 {
				memoization[i] = max(memoization[i], num+memoization[i-2-incr])
				incr++
			}

			result = max(result, memoization[i])
		}
	}

	return result
}
