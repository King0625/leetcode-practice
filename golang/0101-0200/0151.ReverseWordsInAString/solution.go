package leetcode

import "strings"

func reverseWords(s string) string {
	wordSlice := strings.Fields(s)
	
	for i, j := 0, len(wordSlice)-1; i < j; i, j = i+1, j-1 {
		wordSlice[i], wordSlice[j] = wordSlice[j], wordSlice[i]
	}

	result := strings.Join(wordSlice, " ")

	return result
}

