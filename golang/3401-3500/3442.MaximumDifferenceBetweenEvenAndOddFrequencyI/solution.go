package main

func maxDifference(s string) int {
	freq := make(map[rune]int)

	for _, r := range s {
		if _, ok := freq[r]; !ok {
			freq[r] = 1
		} else {
			freq[r]++
		}
	}

	var maxOdd, minEven = 0, 101

	for _, v := range freq {
		if v%2 == 0 && v < minEven {
			minEven = v
		} else if v%2 != 0 && v > maxOdd {
			maxOdd = v
		}
	}

	return maxOdd - minEven
}
