package leetcode

import "math"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxPathSum(root *TreeNode) int {
	result := math.MinInt

	var find func(*TreeNode) int
	find = func(node *TreeNode) int {
		if node == nil {
			return 0
		}
		left := max(find(node.Left), 0)
		right := max(find(node.Right), 0)

		maxIfNodeIsRoot := node.Val + left + right
		result = max(result, maxIfNodeIsRoot)

		return node.Val + max(left, right)
	}

	find(root)
	return result
}
