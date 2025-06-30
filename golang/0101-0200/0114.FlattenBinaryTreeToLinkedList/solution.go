package leetcode

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func flatten(root *TreeNode) {
	var prevNode *TreeNode

	var flat func(*TreeNode)
	flat = func(node *TreeNode) {
		if node != nil {
			flat(node.Right)
			flat(node.Left)

			node.Right = prevNode
			node.Left = nil
			prevNode = node
		}
	}

	flat(root)
}
