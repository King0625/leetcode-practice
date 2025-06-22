package leetcode

func maxDepth(root *TreeNode) int {
	var result int
	if root == nil {
		return result
	}

	var q []*TreeNode
	q = append(q, root)

	for len(q) != 0 {
		result++
		currentLen := len(q)
		for i := 0; i < currentLen; i++ {
			node := q[0]
			q = q[1:]
			if node.Left != nil {
				q = append(q, node.Left)
			}

			if node.Right != nil {
				q = append(q, node.Right)
			}
		}
	}

	return result
}
