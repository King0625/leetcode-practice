package main

import "fmt"

func longestConsecutive(nums []int) int {
	numMap := make(map[int]bool)
	for _, num := range nums {
		numMap[num] = true
	}

	result := 0

	for num, _ := range numMap {
		
		// check if it is the start
		if !numMap[num-1] {
			currentNum := num
			length := 1
			for numMap[currentNum+1] {
				length++
				currentNum++
			}

			if result < length {
				result = length
			}
		}

	}

	return result
}

func main() {
	nums := []int{1,0,1,2}
	fmt.Println(longestConsecutive(nums))
}
