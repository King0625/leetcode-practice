package main

import "strings"

func fullJustify(words []string, maxWidth int) []string {
	var result []string

	formWordGroup := func(currentLen, left, right int) string {
		var wordGroup string
		gaps := right - left
		if gaps == 0 {
			endSpaces := maxWidth - len(words[left])
			wordGroup = words[left] + strings.Repeat(" ", endSpaces)
		} else {
			avgSpaces := (maxWidth - currentLen) / gaps
			extraSpaces := (maxWidth - currentLen) % gaps

			for i := 0; i < gaps; i++ {
				wordGroup += words[left+i] + strings.Repeat(" ", avgSpaces)
				if extraSpaces > 0 {
					wordGroup += " "
					extraSpaces--
				}
			}

			wordGroup += words[right]
		}
		return wordGroup
	}

	left, right, currentLen := 0, 0, 0

	for right = 0; right < len(words); right++ {
		wordLen := len(words[right])

		if currentLen+wordLen < maxWidth-(right-left) {
			currentLen += wordLen
		} else if currentLen+wordLen > maxWidth-(right-left) {
			wordGroup := formWordGroup(currentLen, left, right-1)
			result = append(result, wordGroup)
			left = right
			currentLen = len(words[right])
		} else {
			currentLen += wordLen
			wordGroup := formWordGroup(currentLen, left, right)
			result = append(result, wordGroup)
			left = right + 1
			currentLen = 0
		}
	}

	if currentLen != 0 {
		var remain string
		endSpaces := (maxWidth - currentLen) - (right - left - 1)
		var j int
		for j = left; j < right-1; j++ {
			remain += words[j] + " "
		}
		remain += words[j] + strings.Repeat(" ", endSpaces)
		result = append(result, remain)
	}

	return result
}
