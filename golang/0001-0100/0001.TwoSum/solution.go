package leetcode

func twoSum(nums []int, target int) []int {
	subtractMap := make(map[int]int)

	for i, num := range nums {
        diff := target-num
		if val, ok := subtractMap[num]; ok {
            return []int{val, i}
		} else {
			subtractMap[diff] = i
		}
	}

	return nil
}

