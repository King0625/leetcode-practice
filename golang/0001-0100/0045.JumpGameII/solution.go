package leetcode

func jump(nums []int) int {
	size := len(nums)
	maxReach, minJumps, currEnd := 0, 0, 0

	for i := 0; i < size-1; i++ {
		if i+nums[i] > maxReach {
			maxReach = i + nums[i]
		}

		if i == currEnd {
			minJumps++
			currEnd = maxReach
		}
	}

	return minJumps
}
