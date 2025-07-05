package leetcode

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func hasPathSum(root *TreeNode, targetSum int) bool {
	if root == nil {
		return false
	}

	var inorder func(*TreeNode, int) bool
	inorder = func(node *TreeNode, currSum int) bool {
		// got leaf
		currSum += node.Val
		if node.Left == nil && node.Right == nil {
			return currSum == targetSum
		}

		resultLeft, resultRight := false, false
		if node.Left != nil {
			resultLeft = inorder(node.Left, currSum)
		}
		if node.Right != nil {
			resultRight = inorder(node.Right, currSum)
		}

		return resultLeft || resultRight
	}

	return inorder(root, 0)
}
