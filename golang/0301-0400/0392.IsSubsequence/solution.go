package leetcode

func isSubsequence(s string, t string) bool {
	idxS, idxT := 0, 0
	for idxS < len(s) && idxT < len(t) {
		if s[idxS] == t[idxT] {
			idxS++
		}
		idxT++
	}

	return idxS == len(s)
}
