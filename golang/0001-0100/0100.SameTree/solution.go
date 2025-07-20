package leetcode

func preorder(root *TreeNode) []*TreeNode {
	var nodeSlice []*TreeNode
	var solve func(*TreeNode)
	solve = func(node *TreeNode) {
		nodeSlice = append(nodeSlice, node)
		if node == nil {
			return
		}
		solve(node.Left)
		solve(node.Right)
	}

	solve(root)
	return nodeSlice
}

func isSameTree(p *TreeNode, q *TreeNode) bool {
	arrP := preorder(p)
	arrQ := preorder(q)

	if len(arrP) != len(arrQ) {
		return false
	}

	for i := 0; i < len(arrP); i++ {
		if arrP[i] == nil && arrQ[i] == nil {
			continue
		} else if arrP[i] == nil || arrQ[i] == nil {
			return false
		}

		if arrP[i].Val != arrQ[i].Val {
			return false
		}
	}

	return true
}
