package main

import "fmt"
import "strconv"

func generateTenPalindromes(from int) []string {
	var palindromes []string

	// i is the "half" we mirror
	for i := from; len(palindromes) < 10; i++ {
		s := strconv.Itoa(i)

		// Odd-length palindrome: e.g. i=12 → "12" + "1" = "121"
		odd := s + reverseString(s[:len(s)-1])
		palindromes = append(palindromes, odd)

		// Even-length palindrome: e.g. i=12 → "12" + "21" = "1221"
		even := s + reverseString(s)
		palindromes = append(palindromes, even)

		if len(palindromes) >= count {
			break
		}

	}

	return palindromes
}

func reverseString(s string) string {
	runes := []rune(s)
	n := len(runes)
	for i := 0; i < n/2; i++ {
		runes[i], runes[n-1-i] = runes[n-1-i], runes[i]
	}
	return string(runes)
}


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
