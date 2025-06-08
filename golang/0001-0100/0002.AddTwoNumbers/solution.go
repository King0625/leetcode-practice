package leetcode

type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var digits1, digits2 []int

	for l1 != nil {
		digits1 = append(digits1, l1.Val)
		l1 = l1.Next
	}

	for l2 != nil {
		digits2 = append(digits2, l2.Val)
		l2 = l2.Next
	}

	var i1, i2 int
	var hasCarry bool
	result := &ListNode{Val: 0}
	dummy := result

	for i1 < len(digits1) || i2 < len(digits2) {
		var newNum int
		if hasCarry {
			newNum++
		}

		if i2 >= len(digits2) {
			newNum += digits1[i1]
			i1++
		} else if i1 >= len(digits1) {
			newNum += digits2[i2]
			i2++
		} else {
			newNum += digits1[i1] + digits2[i2]
			i1++
			i2++
		}

		if newNum/10 > 0 {
			hasCarry = true
			newNum %= 10
		} else {
			hasCarry = false
		}

		dummy.Next = &ListNode{Val: newNum}
		dummy = dummy.Next
	}

	if hasCarry {
		dummy.Next = &ListNode{Val: 1}
	}

	return result.Next
}
