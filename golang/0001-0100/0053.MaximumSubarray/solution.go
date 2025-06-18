package leetcode

import "math"

func maxSubArray(nums []int) int {
	currentSum, maxSum := nums[0], nums[0]

	for i := 1; i < len(nums); i++ {
		currentSum = int(math.Max(float64(nums[i]), float64(currentSum+nums[i])))
		maxSum = int(math.Max(float64(currentSum), float64(maxSum)))
	}

	return maxSum
}
