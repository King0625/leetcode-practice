package leetcode

import "strings"

func LengthOfLastWord(s string) int {
	words := strings.Fields(s)

	lastWord := words[len(words)-1]

	return len(lastWord)
}
