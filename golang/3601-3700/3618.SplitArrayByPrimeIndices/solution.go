package leetcode

func splitArray(nums []int) int64 {
	var primeSum, otherSum int
	for i, num := range nums {
		if isPrime(i) {
			primeSum += num
		} else {
			otherSum += num
		}
	}

	return int64(math.Abs(float64(primeSum - otherSum)))
}

func isPrime(n int) bool {
	if n <= 1 {
		return false
	}
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}
