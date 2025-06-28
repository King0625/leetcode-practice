package leetcode

import "container/heap"

// minHeap
type MinHeap []int

func (h MinHeap) Len() int           { return len(h) }
func (h MinHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h MinHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MinHeap) Push(x any) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*h = append(*h, x.(int))
}

func (h *MinHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

type MaxHeap []int

func (h MaxHeap) Len() int           { return len(h) }
func (h MaxHeap) Less(i, j int) bool { return h[i] > h[j] } // actually greater than
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

type MedianFinder struct {
	minHeap *MinHeap
	maxHeap *MaxHeap
}

func Constructor() MedianFinder {
	minHeap := &MinHeap{}
	maxHeap := &MaxHeap{}
	heap.Init(minHeap)
	heap.Init(maxHeap)

	return MedianFinder{minHeap, maxHeap}
}

func (this *MedianFinder) AddNum(num int) {
	lenMinHeap := this.minHeap.Len()
	lenMaxHeap := this.maxHeap.Len()

	if lenMinHeap == lenMaxHeap {
		if lenMinHeap == 0 {
			heap.Push(this.minHeap, num)
		} else {
			topMinHeap := (*this.minHeap)[0]
			if num >= topMinHeap {
				heap.Push(this.minHeap, num)
			} else {
				heap.Push(this.maxHeap, num)
			}
		}
		return
	}

	if lenMinHeap > lenMaxHeap {
		topMinHeap := (*this.minHeap)[0]
		if num > topMinHeap {
			heap.Push(this.minHeap, num)
			heap.Pop(this.minHeap)
			heap.Push(this.maxHeap, topMinHeap)
		} else {
			heap.Push(this.maxHeap, num)
		}

		return
	}

	if lenMaxHeap > lenMinHeap {
		topMaxHeap := (*this.maxHeap)[0]
		if num < topMaxHeap {
			heap.Push(this.maxHeap, num)
			heap.Pop(this.maxHeap)
			heap.Push(this.minHeap, topMaxHeap)
		} else {
			heap.Push(this.minHeap, num)
		}
		return
	}
}

func (this *MedianFinder) FindMedian() float64 {
	lenMinHeap := this.minHeap.Len()
	lenMaxHeap := this.maxHeap.Len()
	topMinHeap := (*this.minHeap)[0]

	if lenMinHeap == lenMaxHeap {
		topMaxHeap := (*this.maxHeap)[0]

		return float64(topMinHeap+topMaxHeap) / 2.0
	} else if lenMinHeap > lenMaxHeap {
		return float64(topMinHeap)
	} else {
		return float64((*this.maxHeap)[0])
	}
}
