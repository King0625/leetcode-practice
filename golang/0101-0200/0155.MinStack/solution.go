package main

type Node [2]int

type MinStack struct {
	nodes []Node
	size  int
}

func Constructor() MinStack {
	return MinStack{
		nodes: []Node{},
		size:  0,
	}
}

func (this *MinStack) Push(val int) {
	var node Node
	if this.size == 0 {
		node = Node{val, val}
	} else {
		topNode := this.nodes[this.size-1]
		minimum := topNode[1]
		if topNode[1] > val {
			minimum = val
		}
		node = Node{val, minimum}
	}

	this.nodes = append(this.nodes, node)
	this.size++
}

func (this *MinStack) Pop() {
	if this.size != 0 {
		this.nodes = this.nodes[:this.size-1]
		this.size--
	}
}

func (this *MinStack) Top() int {
	topNode := this.nodes[this.size-1]
	return topNode[0]
}

func (this *MinStack) GetMin() int {
	topNode := this.nodes[this.size-1]
	return topNode[1]
}
