package leetcode

func hasCycle(adj [][]int) bool {
	size := len(adj)
	inDegree := make([]int, size)

	for i := 0; i < size; i++ {
		for _, neighbor := range adj[i] {
			inDegree[neighbor]++
		}
	}

	var queue []int
	for i, node := range inDegree {
		if node == 0 {
			queue = append(queue, i)
		}
	}

	var topoResult []int
	for len(queue) > 0 {
		node := queue[0]
		queue = queue[1:]

		for _, neighbor := range adj[node] {
			inDegree[neighbor]--
			if inDegree[neighbor] == 0 {
				queue = append(queue, neighbor)
			}
		}
		topoResult = append(topoResult, node)
	}

	return len(topoResult) == size
}

func canFinish(numCourses int, prerequisites [][]int) bool {
	adj := make([][]int, numCourses)
	for i := range numCourses {
		adj[i] = make([]int, 0, numCourses)
	}

	for _, preq := range prerequisites {
		adj[preq[1]] = append(adj[preq[1]], preq[0])
	}

	return hasCycle(adj)
}
