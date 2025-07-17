package leetcode

func combinationSum(candidates []int, target int) [][]int {
	var result [][]int
	var nums []int

	var backtrack func(int, int)
	backtrack = func(currSum, idx int) {
		if currSum == target {
			finishedNums := make([]int, len(nums))
			copy(finishedNums, nums)
			result = append(result, finishedNums)
			return
		}

		if currSum > target || idx >= len(candidates) {
			return
		}

		nums = append(nums, candidates[idx])
		backtrack(currSum+candidates[idx], idx)
		nums = nums[:len(nums)-1]
		backtrack(currSum, idx+1)
	}

	backtrack(0, 0)
	return result
}
