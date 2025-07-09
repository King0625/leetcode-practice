package leetcode

type NodePair struct {
	node   *TreeNode
	isLeft bool
}

func isSymmetric(root *TreeNode) bool {
	var queue []*NodePair
	if root.Left != nil {
		queue = append(queue, &NodePair{root, true})
	}

	if root.Right != nil {
		queue = append(queue, &NodePair{root, false})
	}

	if len(queue)%2 != 0 {
		return false
	}

	for len(queue) > 0 {
		qSize := len(queue)
		nodes := make([]*NodePair, qSize)
		for i := 0; i < qSize; i++ {
			root := queue[0]
			queue = queue[1:]
			nodes[i] = root
			if root.node == nil {
				continue
			}
			if root.node.Left != nil {
				queue = append(queue, &NodePair{root.node.Left, true})
			} else {
				queue = append(queue, &NodePair{nil, true})
			}

			if root.node.Right != nil {
				queue = append(queue, &NodePair{root.node.Right, false})
			} else {
				queue = append(queue, &NodePair{nil, false})
			}
		}

		left, right := 0, qSize-1
		for left <= right {
			if nodes[left].node == nil && nodes[right].node != nil {
				return false
			} else if nodes[left].node != nil && nodes[right].node == nil {
				return false
			} else if nodes[left].node != nil && nodes[right].node != nil {
				if nodes[left].node.Val != nodes[right].node.Val {
					return false
				}

			}

			if nodes[left].isLeft == nodes[right].isLeft {
				return false
			}
			left++
			right--
		}
	}

	return true
}
