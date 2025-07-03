package leetcode

func canConstruct(ransomNote string, magazine string) bool {
	var magazineFreq [26]int

	for _, rm := range magazine {
		at := int(rm - 'a')
		magazineFreq[at]++
	}

	for _, rr := range ransomNote {
		at := int(rr - 'a')
		if magazineFreq[at] <= 0 {
			return false
		} else {
			magazineFreq[at]--
		}
	}

	return true
}
