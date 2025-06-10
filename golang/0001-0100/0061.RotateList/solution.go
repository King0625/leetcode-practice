package leetcode

type ListNode struct {
	Val  int
	Next *ListNode
}

func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	var listLen int

	dummy := head

	for dummy != nil {
		listLen++
		dummy = dummy.Next
	}

	dummy = head

	realK := k % listLen
	
	if realK == 0 {
		return head
	}

	for listLen-1 > realK {
		dummy = dummy.Next
		listLen--
	}

	rotated := dummy.Next

	dummy.Next = nil

	dummy = rotated

	for realK > 1 {
		dummy = dummy.Next
		realK--
	}

	dummy.Next = head

	return rotated
}

