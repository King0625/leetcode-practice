package leetcode

func findPeakElement(nums []int) int {
	left, right := 0, len(nums)-1

	for left <= right {
		mid := left + (right-left)/2
		if mid == 0 {
			if len(nums) == 1 || nums[mid+1] < nums[mid] {
				return mid
			}
			left++
		} else if mid == len(nums)-1 {
			if nums[mid-1] < nums[mid] {
				return mid
			}
			right--
		} else {
			leftVal, midVal, rightVal := nums[mid-1], nums[mid], nums[mid+1]
			if midVal > leftVal && midVal > rightVal {
				return mid
			} else if midVal < rightVal {
				left++
			} else {
				right--
			}
		}
	}

	return -1
}
