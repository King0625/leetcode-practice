package leetcode

import "container/heap"

type ListNode struct {
    Val int
    Next *ListNode
}

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x any) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}


func mergeKLists(lists []*ListNode) *ListNode {
	h := &IntHeap{}
	heap.Init(h)
	for _, list := range lists {
		for list != nil {
			heap.Push(h, list.Val)
			list = list.Next
		}
	}

	newList := ListNode{0,nil}
	dummy := &newList

	for h.Len() > 0 {
		val := heap.Pop(h)
		dummy.Next = &ListNode{val.(int),nil}
		dummy = dummy.Next
	}

	return newList.Next
}

