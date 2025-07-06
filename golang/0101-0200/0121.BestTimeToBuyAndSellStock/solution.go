package leetcode

func maxProfit(prices []int) int {
	size := len(prices)
	profits := make([]int, size)
	lowestPrice := prices[0]

	for i := 1; i < size; i++ {
		if prices[i] < lowestPrice {
			profits[i] = profits[i-1]
			lowestPrice = prices[i]
		} else {
			profits[i] = max(profits[i-1], prices[i]-lowestPrice)
		}
	}

	return profits[size-1]
}
