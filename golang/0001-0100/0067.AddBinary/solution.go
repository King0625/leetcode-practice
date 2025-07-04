package leetcode

func addBinary(a string, b string) string {
	idxA, idxB := len(a)-1, len(b)-1
	hasCarry := false
	result := ""

	for idxA >= 0 || idxB >= 0 {
		oneCount := 0
		if hasCarry {
			oneCount++
		}

		if idxA >= 0 {
			if a[idxA] == byte('1') {
				oneCount++
			}
			idxA--
		}

		if idxB >= 0 {
			if b[idxB] == byte('1') {
				oneCount++
			}
			idxB--
		}

		if oneCount/2 == 1 {
			hasCarry = true
		} else {
			hasCarry = false
		}

		if oneCount%2 == 1 {
			result = "1" + result
		} else {
			result = "0" + result
		}
	}

	if hasCarry {
		result = "1" + result
	}

	return result
}
