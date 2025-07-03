package leetcode

func isIsomorphic(s string, t string) bool {
	size := len(s)
	letterMapST := make(map[rune]rune)
	letterMapTS := make(map[rune]rune)
	result := true

	for i := 0; i < size; i++ {
		rs := rune(s[i])
		rt := rune(t[i])
		valS, okS := letterMapST[rs]
		valT, okT := letterMapTS[rt]

		if !okS && !okT {
			letterMapST[rs] = rt
			letterMapTS[rt] = rs
		} else if (!okS && okT) || (okS && !okT) {
			result = false
			break
		} else if okS && okT {
			if valS != rt || valT != rs {
				result = false
				break
			}
		}
	}

	return result
}
