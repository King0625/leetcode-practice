package leetcode

import "sort"

func carFleet(target int, position []int, speed []int) int {
	carCount := len(position)
	carInfos := make([][2]int, carCount)
	for i := 0; i < carCount; i++ {
		carInfos[i][0] = position[i]
		carInfos[i][1] = speed[i]
	}
	sort.Slice(carInfos, func(a, b int) bool {
		return carInfos[a][0] > carInfos[b][0]
	})

	var time []float64 = make([]float64, 0, carCount)
	for i := range carInfos {
		currTime := float64(target-carInfos[i][0]) / float64(carInfos[i][1])

		if len(time) == 0 || currTime > time[len(time)-1] {
			time = append(time, currTime)
		}
	}

	return len(time)
}
