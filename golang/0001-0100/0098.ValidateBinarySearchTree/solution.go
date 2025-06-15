package leetcode

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func inOrder(root *TreeNode, ch chan int) {
	if root != nil {
		inOrder(root.Left, ch)
		ch <- root.Val
		inOrder(root.Right, ch)
	}
}

func walk(root *TreeNode, ch chan int) {
	inOrder(root, ch)
	defer close(ch)
}

func isValidBST(root *TreeNode) bool {
	ch := make(chan int)

	go walk(root, ch)

	prevVal, _ := <-ch

	for {
		val, ok := <-ch
		if !ok {
			break
		}
		
		if val < prevVal {
			return false
		}

		prevVal = val
	}

	return true
}

