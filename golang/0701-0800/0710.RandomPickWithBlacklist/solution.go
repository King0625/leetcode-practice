package leetcode

import "math/rand"

type Solution struct {
	Size int
	Set map[int]int
}

func Constructor(n int, blacklist []int) Solution {
	sol := Solution{
		n - len(blacklist),
		map[int]int{},
	}

	for _, v := range blacklist {
		sol.Set[v] = -1
	}

	// if blacklist num picked, replace it with others
	for _, v := range blacklist {
		if v < s.Size {
			for n > 0 {
				n--
				if _, ok := s.Set[n]; !ok {
					s.Set[v] = n
					break
				}
			}
		}
	}

}


func (this *Solution) Pick() int {
	pick := rand.Intn(this.Size)
	if val, ok := this.Set[pick]; ok {
		return val
	}

	return pick
}

