package main

import "fmt"

func possibleStringCount(word string) int {
	var letterMap [26]int

	lastLetterAt := -1
	for _, r := range word {
		at := int(r - 'a')
		if lastLetterAt == at {
			letterMap[at]++
		}

		lastLetterAt = at
	}

	result := 1
	for _, count := range letterMap {
		result += count - 1
	}

	return result
}

func main() {
	word := "ere"
	fmt.Println(possibleStringCount(word))
}
