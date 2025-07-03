package leetcode

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func preorder(root *TreeNode, result *int, sum int) {
	sum = sum*10 + root.Val
	if root.Right == nil && root.Left == nil {
		*result += sum
		return
	}

	if root.Left != nil {
		preorder(root.Left, result, sum)
	}

	if root.Right != nil {
		preorder(root.Right, result, sum)
	}
}

func sumNumbers(root *TreeNode) int {
	var result int
	preorder(root, &result, 0)
	return result
}
