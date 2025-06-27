package leetcode

type WeightedPath struct {
	To int
	Weight float64
}

func calcEquation(equations [][]string, values []float64, queries [][]string) []float64 {
	idx := 0
	variableMap := make(map[string]int) 
	for _, equation := range equations {
		dividend := equation[0]
		divisor := equation[1]

		if _, ok := variableMap[dividend]; !ok {
			variableMap[dividend] = idx
			idx++
		}

		if _, ok := variableMap[divisor]; !ok {
			variableMap[divisor] = idx
			idx++
		}
	}

	adjList := make([][]WeightedPath, idx)
	for i := 0; i < len(values); i++ {
		varAt := variableMap[equations[i][0]]
		varTo := variableMap[equations[i][1]]
		
		weightedPathOut := WeightedPath{
			varTo,
			values[i],
		}
		adjList[varAt] = append(adjList[varAt], weightedPathOut)

		weightedPathIn := WeightedPath{
			varAt,
			1/values[i],
		}
		adjList[varTo] = append(adjList[varTo], weightedPathIn)
	}

	var calcPath func(int, int, []bool) float64
	calcPath = func(at, to int, visited []bool) float64 {
		if at == to {
			return 1.0
		}

		visited[at] = true
		for _, node := range adjList[at] {
			if visited[node.To] {
				continue
			}

			result := calcPath(node.To, to, visited)
			if result > 0 {
				return result * node.Weight
			}
		}

		return -1.0
	}

	var result []float64
	for _, query := range queries {
		if _, ok := variableMap[query[0]]; !ok {
			result = append(result, -1.0)
			continue
		}

		if _, ok := variableMap[query[1]]; !ok {
			result = append(result, -1.0)
			continue
		}

		if query[0] == query[1] {
			result = append(result, 1.0)
		} else {
			at := variableMap[query[0]]
			to := variableMap[query[1]]
			visited := make([]bool, idx)
			val := calcPath(at, to, visited)
			result = append(result, val)
		}
	}
	return result
}

