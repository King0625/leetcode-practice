package leetcode

type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func LevelOrder(root *TreeNode) [][]int {
	var result [][]int

	if root == nil {
		return result
	}

	var q []*TreeNode
	q = append(q, root)

	for len(q) != 0 {
		var levelSlice []int
		qLen := len(q)
		for i := 0; i < qLen; i++ {
			node := q[0]
			levelSlice = append(levelSlice, node.Val)
			q = q[1:]
			if node.Left != nil {
				q = append(q, node.Left)
			}
			if node.Right != nil {
				q = append(q, node.Right)
			}
		}

		result = append(result, levelSlice)
	}

	return result
}

// func main() {
// 	root := TreeNode{3,nil,nil}
// 	root.Left = &TreeNode{9,nil,nil}
// 	root.Right = &TreeNode{20,nil,nil}
// 	root.Right.Left = &TreeNode{15,nil,nil}
// 	root.Right.Right = &TreeNode{7,nil,nil}
// 
// 	result := LevelOrder(&root)
// 
// 	for _, levelSlice := range result {
// 		for _, el := range levelSlice {
// 			fmt.Printf("%d ", el)
// 		}
// 		fmt.Println("")
// 	}
// }
