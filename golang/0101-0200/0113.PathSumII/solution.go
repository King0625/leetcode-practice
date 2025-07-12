package leetcode

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func copySlice(sl []int) []int {
	newSlice := make([]int, len(sl))
	copy(newSlice, sl)
	return newSlice
}

func pathSum(root *TreeNode, targetSum int) [][]int {
	var result [][]int

	if root == nil {
		return result
	}

	var nums []int

	var preorder func(*TreeNode, []int, int)

	preorder = func(node *TreeNode, nums []int, sum int) {
		val := node.Val
		nums = append(nums, val)
		sum += val
		if node.Left == nil && node.Right == nil {
			if sum == targetSum {
				result = append(result, nums)
			}
			return
		}

		if node.Left != nil {
			newNums := copySlice(nums)
			preorder(node.Left, newNums, sum)
		}

		if node.Right != nil {
			newNums := copySlice(nums)
			preorder(node.Right, newNums, sum)
		}
	}

	preorder(root, nums, 0)

	return result
}
