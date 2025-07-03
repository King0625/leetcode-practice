package leetcode

func maximumDifference(nums []int) int {
	result := -1

	minNum := nums[0]

	for i := 1; i < len(nums); i++ {
		if nums[i] < minNum {
			minNum = nums[i]
		}

		if nums[i] > minNum && nums[i]-minNum > result {
			result = nums[i] - minNum
		}

	}

	return result
}
