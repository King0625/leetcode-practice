package leetcode

func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	freq := make(map[rune]int)

	for _, rs := range s {
		if _, ok := freq[rs]; !ok {
			freq[rs] = 1
		} else {
			freq[rs]++
		}
	}

	for _, rt := range t {
		if _, ok := freq[rt]; !ok {
			return false
		}

		freq[rt]--

		if freq[rt] == 0 {
			delete(freq, rt)
		}
	}

	return true
}
