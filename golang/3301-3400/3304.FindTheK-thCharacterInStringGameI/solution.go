package leetcode

func kthCharacter(k int) byte {
	currK := k
	steps := 0
	for currK > 0 {
		currK /= 2
		steps++
	}

	resultString := "a"
	for steps >= 0 {
		steps--
		newStringPart := ""
		for _, r := range resultString {
			newStringPart += string(r + 1)
		}

		resultString += newStringPart
	}

	return byte(resultString[k-1])
}
