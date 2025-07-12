package leetcode

import "sort"
import "container/heap"

type Pair struct {
	capital int
	profit  int
}

type MaxHeap []int

func (h MaxHeap) Len() int           { return len(h) }
func (h MaxHeap) Less(i, j int) bool { return h[i] > h[j] }
func (h MaxHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MaxHeap) Push(x any) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*h = append(*h, x.(int))
}

func (h *MaxHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func findMaximizedCapital(k int, w int, profits []int, capital []int) int {
	size := len(profits)
	pairs := make([]Pair, size)
	for i := 0; i < size; i++ {
		pair := Pair{
			capital[i], profits[i],
		}
		pairs[i] = pair
	}

	sort.Slice(pairs, func(i, j int) bool {
		return pairs[i].capital < pairs[j].capital
	})

	maxHeap := &MaxHeap{}
	heap.Init(maxHeap)
	idx := 0

	for j := 0; j < k; j++ {
		for idx < size && pairs[idx].capital <= w {
			heap.Push(maxHeap, pairs[idx].profit)
			idx++
		}

		if maxHeap.Len() == 0 {
			break
		}

		w += heap.Pop(maxHeap).(int)
	}

	return w
}
