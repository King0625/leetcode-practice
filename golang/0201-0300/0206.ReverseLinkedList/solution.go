package leetcode

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseList(head *ListNode) *ListNode {
	var reversed *ListNode

	for head != nil {
		temp := head.Next
		head.Next = reversed
		reversed = head
		head = temp
	}

	return reversed
}
