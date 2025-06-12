package leetcode

func twoSum(nums []int, target int) []int {
	subtractMap := make(map[int]int)

	var result []int

	for i, num := range nums {
		if _, ok := subtractMap[num]; ok {
			result = append(result, subtractMap[num], i)
		} else {
			subtractMap[target-num] = i
		}
	}

	return result
}

