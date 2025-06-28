package leetcode

func canJump(nums []int) bool {
	maxReach := 0
	for i, num := range nums {
		maxReach = max(maxReach, i+num)
		if maxReach <= i && i < len(nums)-1 {
			return false
		}
	}

	return true
}
