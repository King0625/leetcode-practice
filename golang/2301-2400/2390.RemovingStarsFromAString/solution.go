package leetcode

func removeStars(s string) string {
	var runes []rune

	for _, r := range s {
		if r == '*' {
			currentLen := len(runes)
			if currentLen > 0 {
				runes = runes[:currentLen-1]
			}
		} else {
			runes = append(runes, r)
		}
	}

	return string(runes)
}

