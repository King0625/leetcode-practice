package leetcode

func permute(nums []int) [][]int {
	var result [][]int
	var perm []int

	size := len(nums)
	visited := make([]bool, size)
	
	var solve func()
	solve = func() {
		if len(perm) == size {
			finishedPerm := make([]int, size)
			copy(finishedPerm, perm)
			result = append(result, finishedPerm)
			return
		}

		for i := 0; i < size; i++ {
			if visited[i] {
				continue
			}

			perm = append(perm, nums[i])
			visited[i] = true
			solve()
			perm = perm[:len(perm)-1]
			visited[i] = false
		}
	}

	solve()
	return result
}

