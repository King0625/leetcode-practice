package leetcode

func minWindow(s string, t string) string {
	lenS, lenT := len(s), len(t)

	if s == t {
		return t
	}

	if lenS < lenT {
		return ""
	}

	runeMap := make(map[rune]int)

	for _, r := range t {
		if _, ok := runeMap[r]; !ok {
			runeMap[r] = 1
		} else {
			runeMap[r]++
		}
	}

	left, right := 0, 0
	result := lenS
	var window [2]int
	var got bool

	windowRuneMap := make(map[rune]int)
	additionalRuneMap := make(map[rune]int)

	for k, v := range runeMap {
		windowRuneMap[k] = v
		additionalRuneMap[k] = 0
	}

	runeOfS := []rune(s)
	for left <= right && right < lenS {
		if len(windowRuneMap) > 0 {
			r := runeOfS[right]
			if _, ok := windowRuneMap[r]; ok {
				windowRuneMap[r]--
				if windowRuneMap[r] == 0 {
					delete(windowRuneMap, r)
				}
			} else if _, ok := runeMap[r]; ok {
				additionalRuneMap[r]++
			}

			if len(windowRuneMap) == 0 {
				if result > right-left {
					got = true
					result = right - left
					window[0] = left
					window[1] = right
				}
			} else {
				right++
			}
		} else {
			removedLeft := runeOfS[left]
			left++
			if _, ok := runeMap[removedLeft]; ok {
				if additionalRuneMap[removedLeft] != 0 {
					additionalRuneMap[removedLeft]--
				} else {
					windowRuneMap[removedLeft] = 1
					right++
					continue
				}
			}

			if result > right-left {
				got = true
				result = right - left
				window[0] = left
				window[1] = right
			}

		}
	}

	if !got {
		return ""
	}
	runeResult := runeOfS[window[0] : window[1]+1]
	return string(runeResult)
}
