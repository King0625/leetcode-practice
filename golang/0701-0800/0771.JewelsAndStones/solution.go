package leetcode

func numJewelsInStones(jewels string, stones string) int {
	jewelMap := make(map[rune]bool)

	for _, jewel := range jewels {
		jewelMap[jewel] = true
	}

	count := 0

	for _, stone := range stones {
		if ok, _ := jewelMap[stone]; ok {
			count++
		}
	}

	return count
}
