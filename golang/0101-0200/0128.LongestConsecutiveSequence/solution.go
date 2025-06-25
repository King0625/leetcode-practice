package main

import "fmt"

func longestConsecutive(nums []int) int {
	numMap := make(map[int]bool)
	for _, num := range nums {
		numMap[num] = false
	}

	result := 0

	for _, num := range nums {
		diff := 1

		if _, ok := numMap[num]; ok {
			_, ok := numMap[num+diff]
			for ok {
				diff++
				_, ok = numMap[num+diff]
			}
	
			result = max(result, diff)

		}
		
	}

	return result
}

func main() {
	nums := []int{1,0,1,2}
	fmt.Println(longestConsecutive(nums))
}
