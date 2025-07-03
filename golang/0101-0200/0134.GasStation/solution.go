package main

import "fmt"

func canCompleteCircuit(gas []int, cost []int) int {
	stops := len(gas)
	for i := 0; i < stops; i++ {
		if gas[i] < cost[i] {
			continue
		}

		gasInTank, moved := 0,0
		idx := i
		curr := idx

		for moved < stops {
			gasInTank += gas[curr]
			if gasInTank < cost[curr] {
				idx = -1
				break
			}

			gasInTank -= cost[curr]
			curr = (curr+1) % stops
			moved++
		}

		if idx != -1 {
			return idx
		}
	}

	return -1
}

func main() {
	gas := []int{3,3,4}
	cost := []int{3,4,4}

	fmt.Println(canCompleteCircuit(gas, cost))
}
