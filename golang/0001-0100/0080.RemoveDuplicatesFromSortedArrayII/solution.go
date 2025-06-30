package leetcode

func removeDuplicates(nums []int) int {
	idx := 1
	prevNum := nums[0]
	dupCount := 0

	for i := 1; i < len(nums); i++ {
		if prevNum != nums[i] {
			nums[idx] = nums[i]
			prevNum = nums[i]
			dupCount = 0
			idx++
		} else if prevNum == nums[i] {
			if dupCount < 1 {
				dupCount++
				nums[idx] = nums[i]
				idx++
			}
		}
	}

	fmt.Println(nums)
	return idx
}
