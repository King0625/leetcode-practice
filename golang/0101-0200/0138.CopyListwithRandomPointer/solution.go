package leetcode

type Node struct {
	Val    int
	Next   *Node
	Random *Node
}

func copyRandomList(head *Node) *Node {
	ogNodes := make(map[*Node]int)
	randomMatch := make(map[*Node]*Node)
	dummy := head
	index := 0
	for dummy != nil {
		ogNodes[dummy] = index
		if dummy.Random != nil {
			randomMatch[dummy] = dummy.Random
		}
		dummy = dummy.Next
		index++
	}

	indexRandomMap := make(map[int]int)
	for k, v := range ogNodes {
		if _, ok := randomMatch[k]; ok {
			indexRandomMap[v] = ogNodes[randomMatch[k]]
		}
	}

	newList := Node{-1, nil, nil}
	index = 0
	dummy = &newList
	newNodes := make(map[int]*Node)
	for head != nil {
		if _, ok := newNodes[index]; !ok {
			newNode := Node{head.Val, nil, nil}
			newNodes[index] = &newNode
		}
		dummy.Next = newNodes[index]

		if head.Random == nil {
			continue
		}

		if _, ok := indexRandomMap[index]; ok {
			randomIndex := indexRandomMap[index]
			if _, ok := newNodes[randomIndex]; !ok {
				newRandomNode := Node{head.Random.Val, nil, nil}
				newNodes[randomIndex] = &newRandomNode
			}
			dummy.Next.Random = newNodes[randomIndex]
		}

		index++
		head = head.Next
		dummy = dummy.Next
	}

	return newList.Next
}
