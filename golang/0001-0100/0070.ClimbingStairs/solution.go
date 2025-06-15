package leetcode

func climbStairs(n int) int {
	prev1, prev2 := 1, 1

	for i := 2; i <= n; i++ {
		ways := prev1 + prev2
		prev2 = prev1
		prev1 = ways
	}

	return prev1
}
