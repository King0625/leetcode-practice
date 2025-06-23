package leetcode

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func buildTree(preorder []int, inorder []int) *TreeNode {
	preIdx := 0
	idxMap := make(map[int]int)
	for i, val := range inorder {
		idxMap[val] = i
	}

	var dfs func(int, int) *TreeNode

	dfs = func(l, r int) *TreeNode {
		if l > r {
			return nil
		}

		rootVal := preorder[preIdx]
		preIdx++
		root := &TreeNode{rootVal, nil, nil}
		mid := idxMap[rootVal]

		root.Left = dfs(l, mid-1)
		root.Right = dfs(mid+1, r)

		return root
	}

	return dfs(0, len(inorder)-1)
}
