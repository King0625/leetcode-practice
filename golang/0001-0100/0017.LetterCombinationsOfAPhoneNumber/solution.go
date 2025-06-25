package leetcode

func letterCombinations(digits string) []string {
	phoneLetterMap := map[rune][]int{
		'2': {0,2},
		'3': {3,5},
		'4': {6,8},
		'5': {9,11},
		'6': {12,14},
		'7': {15,18},
		'8': {19,21},
		'9': {22,25},
	}

	var result []string
	var comb string
	wordLen := len(digits)

	if wordLen == 0 {
		return result
	}

	var solve func(int)
	solve = func(start int) {
		if len(comb) == wordLen {
			result = append(result, comb)
			return
		}

		for i := start; i < wordLen; i++ {
			currRune := rune(digits[i])
			letterRng := phoneLetterMap[currRune]
			for j := letterRng[0]; j <= letterRng[1]; j++ {
				comb += string('a' + j)
				solve(i+1)
				comb = comb[:len(comb)-1]
			}
		}
	}

	solve(0)
	return result
}

