package leetcode

import "slices"

func ladderLength(beginWord string, endWord string, wordList []string) int {
	if !slices.Contains(wordList, endWord) {
		return 0
	}

	visitedMap := make(map[string]bool)
	for _, word := range wordList {
		visitedMap[word] = false
	}

	var queue []string
	queue = append(queue, beginWord)

	result := 1
	for len(queue) > 0 {
		qSize := len(queue)
		for i := 0; i < qSize; i++ {
			str := queue[0]
			queue = queue[1:]

			if str == endWord {
				return result
			}
			strRune := []rune(str)
			for j := 0; j < len(str); j++ {
				oldRune := strRune[j]
				for k := 0; k < 26; k++ {
					strRune[j] = rune(97 + k)
					newStr := string(strRune)
					if visited, ok := visitedMap[newStr]; ok {
						if !visited {
							queue = append(queue, newStr)
							visitedMap[newStr] = true
						}
					}

				}
				strRune[j] = oldRune
			}
		}

		result++
	}

	return 0
}
