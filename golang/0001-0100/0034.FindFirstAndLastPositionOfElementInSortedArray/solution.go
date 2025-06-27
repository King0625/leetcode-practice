package leetcode

func searchRange(nums []int, target int) []int {
	left, right := 0, len(nums)-1
	gotIndex := -1

	for left <= right {
		mid := (right+left) / 2
		val := nums[mid]
		if val == target {
			gotIndex = mid
			break
		} else if val < target {
			left = mid+1
		} else {
			right = mid-1
		}
	}

	if gotIndex == -1 {
		return []int{-1,-1}
	}

	left, right = gotIndex, gotIndex
	leftStop, rightStop := false, false
	for (!leftStop || !rightStop) && (right < len(nums) || left >= 0) {
		if left >= 0 && nums[left] == target {
			left--
		} else {
			leftStop = true
		}

		if right < len(nums) && nums[right] == target {
			right++
		} else {
			rightStop = true
		}
	}

	return []int{left+1, right-1}
}

