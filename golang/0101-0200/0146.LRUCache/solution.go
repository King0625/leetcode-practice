package leetcode

type DLLNode struct {
	Key  int
	Val  int
	Prev *DLLNode
	Next *DLLNode
}

type LRUCache struct {
	Head    *DLLNode
	Tail    *DLLNode
	Cap     int
	NodeMap map[int]*DLLNode
}

func newNode(key, val int) *DLLNode {
	return &DLLNode{
		Key: key,
		Val: val,
	}
}

func Constructor(capacity int) LRUCache {
	head, tail := newNode(0, 0), newNode(0, 0)
	head.Next = tail
	tail.Prev = head
	nodeMap := make(map[int]*DLLNode)
	return LRUCache{
		head, tail, capacity, nodeMap,
	}
}

func (this *LRUCache) Get(key int) int {
	if node, ok := this.NodeMap[key]; ok {
		this.Remove(node)
		this.Insert(node)
		return node.Val
	}

	return -1
}

func (this *LRUCache) Put(key int, value int) {
	if node, ok := this.NodeMap[key]; ok {
		this.Remove(node)
	}

	if len(this.NodeMap) == this.Cap {
		this.Remove(this.Tail.Prev)
	}

	this.Insert(newNode(key, value))
}

func (this *LRUCache) Remove(node *DLLNode) {
	delete(this.NodeMap, node.Key)
	node.Prev.Next = node.Next
	node.Next.Prev = node.Prev
}

func (this *LRUCache) Insert(node *DLLNode) {
	this.NodeMap[node.Key] = node
	next := this.Head.Next
	this.Head.Next = node
	node.Prev = this.Head
	next.Prev = node
	node.Next = next
}
