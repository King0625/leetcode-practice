package leetcode

import "slices"
import "cmp"

func checkMerge(intv1 []int, intv2 []int) bool {
	if intv1[1] >= intv2[0] {
		intv1[1] = max(intv1[1], intv2[1])
		return true
	}

	return false
}

func merge(intervals [][]int) [][]int {
	slices.SortFunc(intervals, func(a, b []int) int {
		return cmp.Compare(a[0], b[0])
	})
	result := [][]int{intervals[0]}

	for i := 1; i < len(intervals); i++ {
		lastResult := result[len(result)-1]
		merged := checkMerge(lastResult, intervals[i])
		if !merged {
			result = append(result, intervals[i])
		}
	}

	return result
}
