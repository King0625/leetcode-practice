package leetcode

import "math"

func minSubArrayLen(target int, nums []int) int {
	minLen := math.MaxInt

	left, right, currentSum := 0, 0, nums[0]

	for left <= right && right < len(nums) {
		currentLen := right - left + 1

		if currentSum < target {
			right++
			if right < len(nums) {
				currentSum += nums[right]
			}
		} else {
			if currentLen < minLen {
				minLen = currentLen
			}

			if currentSum == target {
				currentSum -= nums[left]
				left++
				right++
				if right < len(nums) {
					currentSum += nums[right]
				}
			} else {
				currentSum -= nums[left]
				left++
			}

		}
	}

	if minLen == math.MaxInt {
		return 0
	}
	return minLen
}
