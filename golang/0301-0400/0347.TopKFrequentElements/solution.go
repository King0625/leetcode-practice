package main

import (
	"container/heap"
	"fmt"
)

type Pair struct {
	num   int
	count int
}

type FreqHeap []Pair

func (h FreqHeap) Len() int {
	return len(h)
}

func (h FreqHeap) Less(i, j int) bool {
	return h[i].count > h[j].count
}

func (h FreqHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *FreqHeap) Push(x any) {
	*h = append(*h, x.(Pair))
}

func (h *FreqHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func topKFrequent(nums []int, k int) []int {
	freq := make(map[int]int)

	for _, num := range nums {
		if _, ok := freq[num]; !ok {
			freq[num] = 1
		} else {
			freq[num]++
		}
	}

	var pairSlice FreqHeap

	for k, v := range freq {
		pairSlice = append(pairSlice, Pair{k, v})
	}

	heap.Init(&pairSlice)

	var result []int

	for k > 0 {
		poppedPair := heap.Pop(&pairSlice)
		result = append(result, poppedPair.(Pair).num)
		k--
	}

	return result
}

func main() {
	nums := []int{1, 1, 1, 2, 2, 3}
	k := 2

	result := topKFrequent(nums, k)

	for _, num := range result {
		fmt.Printf("%d ", num)
	}
}
