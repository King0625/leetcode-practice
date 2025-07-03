package leetcode

func searchInsert(nums []int, target int) int {
	left, right := 0, len(nums)-1
	result := -1

	for left <= right {
		mid := (right + left) / 2

		if nums[mid] == target {
			result = mid
			break
		} else if nums[mid] > target {
			right = mid - 1
		} else {
			left = mid + 1
		}
	}

	if result == -1 {
		result = left
	}

	return result
}
