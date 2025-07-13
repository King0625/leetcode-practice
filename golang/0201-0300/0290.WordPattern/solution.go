package leetcode

import "strings"

func wordPattern(pattern string, s string) bool {
	pToS := make(map[rune]string)
	sToP := make(map[string]rune)

	runeP := []rune(pattern)
	sliceS := strings.Split(s, " ")

	if len(runeP) != len(sliceS) {
		return false
	}

	for i := 0; i < len(runeP); i++ {
		r := runeP[i]
		str := sliceS[i]

		_, ok := pToS[r]
		if !ok {
			if _, ok := sToP[str]; ok {
				return false
			}

			pToS[r] = str
			sToP[str] = r
		} else {
			valS, ok := sToP[str]
			if !ok || ok && valS != r {
				return false
			}
		}
	}

	return true
}
