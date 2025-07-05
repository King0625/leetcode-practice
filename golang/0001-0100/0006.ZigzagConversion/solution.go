package leetcode

func convert(s string, numRows int) string {
	lenS := len(s)
	if lenS == 1 || numRows == 1 {
		return s
	}
	strSlice := make([]string, numRows)

	var idx, idxSlice int
	var isDown bool
	for idx < lenS {
		strSlice[idxSlice] += string(s[idx])
		if isDown {
			if idxSlice == numRows-1 {
				isDown = false
				idxSlice--
			} else {
				idxSlice++
			}
		} else {
			if idxSlice == 0 {
				isDown = true
				idxSlice++
			} else {
				idxSlice--
			}
		}

		idx++
	}

	var result string
	for _, str := range strSlice {
		result += str
	}

	return result
}
