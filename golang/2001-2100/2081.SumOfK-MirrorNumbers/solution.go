package main

import "fmt"
import "strconv"

func isPalindrome(numStr string) bool {
	left, right := 0, len(numStr)-1

	for left < right {
		if numStr[left] != numStr[right] {
			return false
		}
		left++
		right--
	}

	return true
}

func kMirror(k int, n int) int64 {
	var result int64
	var currentNum int64 = 1
	for n > 0 {
		decimalNumStr := strconv.FormatInt(currentNum, 10)
		basedNumStr := strconv.FormatInt(currentNum, k)
		
		if isPalindrome(decimalNumStr) && isPalindrome(basedNumStr) {
			fmt.Printf("%s ", decimalNumStr)
			result += currentNum
			n--
		}
		currentNum++
	}

	return result
}

func main() {
	k, n := 7,17
	fmt.Println(kMirror(k,n))
}
