package leetcode

func reverse(nums []int, left, right int) {
	for i, j := left, right; i < j; i, j = i+1, j-1 {
		nums[i], nums[j] = nums[j], nums[i]
	}
}

func rotate(nums []int, k int) {
	size := len(nums)
	realK := k % size

	reverse(nums, 0, size-1)
	reverse(nums, 0, realK-1)
	reverse(nums, realK, size-1)
}
