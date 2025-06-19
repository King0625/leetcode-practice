package leetcode

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type BSTIterator struct {
	InorderNums []int
	index       int
}

func Constructor(root *TreeNode) BSTIterator {
	var inorderNums []int

	var inorderFunc func(root *TreeNode)
	inorderFunc = func(root *TreeNode) {
		if root == nil {
			return
		}

		inorderFunc(root.Left)
		inorderNums = append(inorderNums, root.Val)
		inorderFunc(root.Right)
	}

	inorderFunc(root)

	return BSTIterator{InorderNums: inorderNums, index: -1}
}

func (this *BSTIterator) Next() int {
	this.index++
	return this.InorderNums[this.index]
}

func (this *BSTIterator) HasNext() bool {
	currentIndex := this.index
	inorderNumsLen := len(this.InorderNums)

	return currentIndex < inorderNumsLen-1
}
