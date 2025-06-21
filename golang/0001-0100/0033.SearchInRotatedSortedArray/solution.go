package leetcode

func search(nums []int, target int) int {
	var result = -1

	left, right := 0, len(nums)-1

	for left <= right {
		mid := (left + right) / 2
		leftVal := nums[left]
		rightVal := nums[right]

		if nums[mid] == target {
			result = mid
			break
		}

		if leftVal <= nums[mid] {
			if leftVal <= target && target < nums[mid] {
				right = mid - 1
			} else {
				left = mid + 1
			}
		} else {
			if target > nums[mid] && rightVal >= target {
				left = mid + 1
			} else {
				right = mid - 1
			}
		}
	}

	return result
}
