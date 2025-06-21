package leetcode

import "math/rand"

type RandomizedSet struct {
	IntMap map[int]int
	Set []int
	Len int
}


func Constructor() RandomizedSet {
	return RandomizedSet{
		map[int]int{},
		[]int{},
		0,
	}
}


func (this *RandomizedSet) Insert(val int) bool {
	if _, ok := this.IntMap[val]; !ok {
		this.IntMap[val] = this.Len
		this.Set = append(this.Set, val)
		this.Len++
		return true
	}

	return false
}


func (this *RandomizedSet) Remove(val int) bool {
	v, ok := this.IntMap[val] // found replacing index
	if !ok {
		return false
	}

	last := this.Set[this.Len-1]
	this.Set[v] = last
	this.IntMap[last] = v
	this.Set = this.Set[:this.Len-1]
	this.Len--
	delete(this.IntMap, val)
	return true
}

func (this *RandomizedSet) GetRandom() int {
	randomIndex := rand.Intn(this.Len)
	return this.Set[randomIndex]
}

