package leetcode

type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	var size int
	dummy := head

	for dummy != nil {
		size++
		dummy = dummy.Next
	}

	if size == 1 {
		return nil
	}

	if size == n {
		return head.Next
	}

	dummy = head
	moves := size - n - 1

	for moves > 0 {
		dummy = dummy.Next
		moves--
	}
	dummy.Next = dummy.Next.Next

	return head
}
