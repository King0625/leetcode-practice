package leetcode

import "slices"

var bases [4]rune = [4]rune{'A', 'T', 'C', 'G'}

func minMutation(startGene string, endGene string, bank []string) int {
	var result int

	if len(bank) == 0 {
		return -1
	}

	var queue [][]rune
	queue = append(queue, []rune(startGene))

	seen := make(map[string]bool)

	for len(queue) > 0 {
		currLen := len(queue)

		for i := 0; i < currLen; i++ {
			geneRune := queue[0]
			queue = queue[1:]

			gene := string(geneRune)
			seen[gene] = true
			if string(geneRune) == endGene {
				return result
			}

			for j := 0; j < 8; j++ {
				base := geneRune[j]
				for k := 0; k < 4; k++ {
					geneRune[j] = bases[k]
					possibleGene := string(geneRune)
					_, isSeen := seen[possibleGene]
					if slices.Contains(bank, possibleGene) && !isSeen {
						geneRuneToQueue := make([]rune, 8)
						copy(geneRuneToQueue, geneRune)
						queue = append(queue, geneRuneToQueue)
					}
				}
				geneRune[j] = base
			}
		}

	}

	return -1
}
