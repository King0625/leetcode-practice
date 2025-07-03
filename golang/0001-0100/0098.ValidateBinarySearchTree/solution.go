package leetcode

import "math"

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func isValidBST(root *TreeNode) bool {
	prev := math.MinInt
	var validate func(*TreeNode) bool

	validate = func(root *TreeNode) bool {
		if root == nil {
			return true
		}

		if !validate(root.Left) {
			return false
		}

		if root.Val <= prev {
			return false
		}

		prev = root.Val 

		return validate(root.Right)
	}

	return validate(root)
}

