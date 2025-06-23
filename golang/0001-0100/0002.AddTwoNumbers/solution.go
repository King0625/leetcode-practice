package leetcode

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var hasCarry bool
	var val1, val2 int
	newList := &ListNode{0, nil}
	dummy := newList

	for l1 != nil || l2 != nil {
		if l1 != nil {
			val1 = l1.Val
			l1 = l1.Next
		}

		if l2 != nil {
			val2 = l2.Val
			l2 = l2.Next
		}

		result := val1 + val2
		if hasCarry {
			result += 1
		}

		if result >= 10 {
			result %= 10
			hasCarry = true
		} else {
			hasCarry = false
		}

		dummy.Next = &ListNode{result, nil}
		val1 = 0
		val2 = 0
		dummy = dummy.Next
	}

	if hasCarry {
		dummy.Next = &ListNode{1, nil}
	}

	return newList.Next
}
