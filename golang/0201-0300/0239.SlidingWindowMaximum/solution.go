package main

import (
	"fmt"
	"container/heap"
)

type Pair struct {
	Index int
	Val int
}

type IntPairHeap []Pair

func (h IntPairHeap) Len() int           { return len(h) }
func (h IntPairHeap) Less(i, j int) bool { return h[i].Val > h[j].Val|| (h[i].Val == h[j].Val && h[i].Index < h[j].Index) }
func (h IntPairHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntPairHeap) Push(x any) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*h = append(*h, x.(Pair))
}

func (h *IntPairHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func maxSlidingWindow(nums []int, k int) []int {
	var result []int
	h := &IntPairHeap{}  // maxHeap
	heap.Init(h)
	for i := 0; i < k; i++ {
		heap.Push(h, Pair{i, nums[i]})
	}
	currentMax := (*h)[0].Val

	result = append(result, currentMax)

	for i := k; i < len(nums); i++ {
		pair := Pair{i, nums[i]}
		heap.Push(h, pair)

		for (*h)[0].Index < i-k+1 {
			heap.Pop(h)
		}

		top := (*h)[0]

		result = append(result, top.Val)

		if (*h)[0].Index < i-k+2 {
			heap.Pop(h)
		}

	}

	return result
}

func main() {
	nums := []int{-7,-8,7,5,7,1,6,0}
	k := 4
	result := maxSlidingWindow(nums, k)
	fmt.Println(result)
}
