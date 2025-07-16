package leetcode

func getPermutation(n int, k int) string {
	digitRune := make([]rune, n)
	for i := range n {
		digitRune[i] = rune(i + 1 + '0')
	}

	visited := make([]bool, n)

	var backtrack func()
	var perm []rune
	var result string
	incr := 1
	backtrack = func() {
		if len(perm) == n {
			if incr == k {
				result = string(perm)
			}
			incr++
			return
		}

		for i := 0; i < n; i++ {
			if visited[i] {
				continue
			}
			perm = append(perm, digitRune[i])
			visited[i] = true
			backtrack()
			perm = perm[:len(perm)-1]
			visited[i] = false
		}
	}

	backtrack()
	return result
}
