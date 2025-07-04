package leetcode

import "math"
import "container/heap"

type ValIndex struct {
	val   float64
	index int
}
type ValIndexHeap []ValIndex

func (h ValIndexHeap) Len() int           { return len(h) }
func (h ValIndexHeap) Less(i, j int) bool { return h[i].val < h[j].val }
func (h ValIndexHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *ValIndexHeap) Push(x any) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*h = append(*h, x.(ValIndex))
}

func (h *ValIndexHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func kClosest(points [][]int, k int) [][]int {
	h := &ValIndexHeap{}
	heap.Init(h)

	for i, point := range points {
		value := math.Sqrt(math.Pow(float64(point[0]), 2.0) + math.Pow(float64(point[1]), 2.0))
		valIndex := ValIndex{value, i}
		heap.Push(h, valIndex)
	}

	var result [][]int
	for k > 0 {
		valIndex := heap.Pop(h)
		result = append(result, points[valIndex.(ValIndex).index])
		k--
	}

	return result
}
