package leetcode

func lexicalOrder(n int) []int {
	var result []int
	current := 1

	for i := 0; i < n; i++ {
		result = append(result, current)

		if current*10 <= n {
			current *= 10
		} else {
			for current%10 == 9 || current >= n {
				current /= 10
			}
			current++
		}
	}

	return result
}
