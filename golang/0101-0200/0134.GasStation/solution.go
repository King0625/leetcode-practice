package leetcode

func canCompleteCircuit(gas []int, cost []int) int {
	stops := len(gas)

	totalGas, tank, start := 0, 0, 0

	for i := 0; i < stops; i++ {
		gain := gas[i] - cost[i]
		totalGas += gain
		tank += gain

		if tank < 0 {
			start = i + 1
			tank = 0
		}
	}

	if totalGas < 0 {
		return -1
	}

	return start
}
