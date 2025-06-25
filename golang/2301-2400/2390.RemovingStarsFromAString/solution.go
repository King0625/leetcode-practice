package leetcode

func removeStars(s string) string {
	var bytes []byte

    for i := 0; i < len(s); i++ {
        if s[i] == byte('*') {
            bytes = bytes[:len(bytes)-1]
        } else {
            bytes = append(bytes, s[i])
        }
    }

	return string(bytes)
}

