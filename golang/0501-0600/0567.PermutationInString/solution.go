package leetcode

func checkInclusion(s1 string, s2 string) bool {
	len1, len2 := len(s1), len(s2)
	if len1 > len2 {
		return false
	}
	var freq1, freq2 [26]int

	for i := 0; i < len1; i++ {
		at1 := s1[i] - 'a'
		at2 := s2[i] - 'a'
		freq1[at1]++
		freq2[at2]++
	}

	for i := 0; i < len2-len1; i++ {
		if match(freq1, freq2) {
			return true
		}
		leave := s2[i] - 'a'
		enter := s2[i+len1] - 'a'

		freq2[leave]--
		freq2[enter]++
	}

	return match(freq1, freq2)
}

func match(freq1, freq2 [26]int) bool {
	for i := 0; i < 26; i++ {
		if freq1[i] != freq2[i] {
			return false
		}
	}

	return true
}
