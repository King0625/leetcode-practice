package leetcode

func merge(i1, i2 []int) ([]int, bool) {
	if i1[0] <= i2[0] && i1[1] >= i2[0] {
		return []int{i1[0], max(i2[1], i1[1])}, true
	}

	return nil, false
}

func insert(intervals [][]int, newInterval []int) [][]int {
	var result [][]int

	if len(intervals) == 0 {
		result = append(result, newInterval)
		return result
	}
	// binary search of start time
	left, right := 0, len(intervals)-1

	insertPosition := -1
	for left <= right {
		mid := (left + right) / 2
		midStartTime := intervals[mid][0]
		if midStartTime == newInterval[0] {
			insertPosition = mid + 1
			break
		} else if midStartTime < newInterval[0] {
			left = mid + 1
		} else {
			right = mid - 1
		}
	}

	if insertPosition == -1 {
		insertPosition = left
	}

	if insertPosition == 0 {
		if mergedInterval, ok := merge(newInterval, intervals[0]); ok {
			result = append(result, mergedInterval)
		} else {
			result = append(result, newInterval)
			result = append(result, intervals[0])
		}
		insertPosition++
	} else {
		result = append(result, intervals[:insertPosition]...)
		lastResult := result[len(result)-1]
		if mergedInterval, ok := merge(lastResult, newInterval); ok {
			result[len(result)-1] = mergedInterval
		} else {
			result = append(result, newInterval)
		}
	}

	for i := insertPosition; i < len(intervals); i++ {
		lastResult := result[len(result)-1]
		if mergedInterval, ok := merge(lastResult, intervals[i]); ok {
			result[len(result)-1] = mergedInterval
		} else {
			result = append(result, intervals[i])
		}
	}

	return result
}
