package leetcode

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func diameterOfBinaryTree(root *TreeNode) int {
	var result int
	var find func(*TreeNode) int
	find = func(node *TreeNode) int {
		if node == nil {
			return 0
		}

		left := find(node.Left)
		right := find(node.Right)
		localMax := left + right

		result = max(result, localMax)
		return max(left, right) + 1
	}

	find(root)
	return result
}
