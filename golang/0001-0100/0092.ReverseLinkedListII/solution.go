package leetcode

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseBetween(head *ListNode, left int, right int) *ListNode {
	if head.Next == nil || left == right {
		return head
	}

	dummy := &ListNode{0, head}
	prev := dummy

	for i := 0; i < left-1; i++ {
		prev = prev.Next
	}

	curr := prev.Next

	for i := 0; i < right-left; i++ {
		nextNode := curr.Next
		curr.Next = nextNode.Next
		nextNode.Next = prev.Next
		prev.Next = nextNode
	}

	return dummy.Next
}
