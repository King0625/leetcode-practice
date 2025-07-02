package leetcode

func subsets(nums []int) [][]int {
	size := len(nums)

	var result [][]int
	var subset []int

	var solve func(int)
	solve = func(idx int) {
		if idx == size {
			finished := make([]int, len(subset))
			copy(finished, subset)
			result = append(result, finished)
			return
		}

		subset = append(subset, nums[idx])
		solve(idx + 1)
		subset = subset[:len(subset)-1]

		solve(idx + 1)
	}

	solve(0)
	return result
}
