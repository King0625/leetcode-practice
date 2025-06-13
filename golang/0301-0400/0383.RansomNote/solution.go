package leetcode

func canConstruct(ransomNote string, magazine string) bool {
	magazineFreq := make(map[rune]int)

	for _, rm := range magazine {
		if _, ok := magazineFreq[rm]; !ok {
			magazineFreq[rm] = 1
		} else {
			magazineFreq[rm]++
		}
	}

	for _, rr := range ransomNote {
		if _, ok := magazineFreq[rr]; !ok {
			return false
		}

		magazineFreq[rr]--

		if magazineFreq[rr] == 0 {
			delete(magazineFreq, rr)
		}
	}

	return true
}
