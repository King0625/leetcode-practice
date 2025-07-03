package leetcode

import (
	"slices"
	"strings"
)

func reverseWords(s string) string {
	wordSlice := strings.Fields(s)
	slices.Reverse(wordSlice)
	return strings.Join(wordSlice, " ")
}
