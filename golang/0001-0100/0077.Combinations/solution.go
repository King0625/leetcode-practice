package leetcode

func combine(n int, k int) [][]int {
	var result [][]int
	var comp []int

	var solve func(int)
	solve = func(start int) {
		compSize := len(comp)
		if compSize == k {
			finishedComp := make([]int, k)
			copy(finishedComp, comp)
			result = append(result, finishedComp)
			return
		}

		for i := start; i <= n; i++ {
			comp = append(comp, i)
			solve(i + 1)
			comp = comp[:len(comp)-1]
		}
	}

	solve(1)
	return result
}
