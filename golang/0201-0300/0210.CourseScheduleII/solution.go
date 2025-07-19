package leetcode

func findOrder(numCourses int, prerequisites [][]int) []int {
	graph := make([][]int, numCourses)
	for i := range numCourses {
		graph[i] = make([]int, 0, numCourses)
	}

	for _, preq := range prerequisites {
		from, to := preq[1], preq[0]
		graph[from] = append(graph[from], to)
	}

	var topoSort func() []int
	topoSort = func() []int {
		size := len(graph)
		inDegree := make([]int, size)

		for i := 0; i < size; i++ {
			for _, node := range graph[i] {
				inDegree[node]++
			}
		}

		fmt.Println(inDegree)
		var queue []int
		for i := 0; i < size; i++ {
			if inDegree[i] == 0 {
				queue = append(queue, i)
			}
		}

		var topoOrder []int

		for len(queue) > 0 {
			node := queue[0]
			queue = queue[1:]

			topoOrder = append(topoOrder, node)
			for _, neighbor := range graph[node] {
				inDegree[neighbor]--
				if inDegree[neighbor] == 0 {
					queue = append(queue, neighbor)
				}
			}
		}

		if len(topoOrder) != numCourses {
			return []int{}
		}

		return topoOrder
	}

	return topoSort()
}
