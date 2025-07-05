package leetcode

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func zigzagLevelOrder(root *TreeNode) [][]int {
	var result [][]int
	if root == nil {
		return result
	}

	queue := []*TreeNode{root}
	level := 1

	for len(queue) > 0 {
		qSize := len(queue)
		nums := make([]int, qSize)

		for i := 0; i < qSize; i++ {
			node := queue[0]
			queue = queue[1:]
			idx := i
			if level%2 == 0 {
				idx = qSize - i - 1
			}
			nums[idx] = node.Val

			if node.Left != nil {
				queue = append(queue, node.Left)
			}

			if node.Right != nil {
				queue = append(queue, node.Right)
			}
		}

		result = append(result, nums)
		level++
	}

	return result
}
