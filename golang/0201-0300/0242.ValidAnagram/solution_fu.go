package leetcode

func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	var freq [26]int

	for _, rs := range s {
		at := int(rs - 'a')
		freq[at]++
	}

	for _, rt := range t {
		at := int(rt - 'a')
		if freq[at] == 0 {
			return false
		}

		freq[at]--
	}

	return true
}
