package leetcode

func twoSum(numbers []int, target int) []int {
	var result []int
	left, right := 0, len(numbers)-1

	for left < right {
		sum := numbers[left] + numbers[right]

		if sum == target {
			result = append(result, left+1, right+1)
			break
		} else if sum > target {
			right--	
		} else if sum < target {
			left++
		}
	}

	return result
}

