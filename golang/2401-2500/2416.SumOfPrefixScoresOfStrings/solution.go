package leetcode

type TrieNode struct {
	Val      int
	Score    int
	Children [26]*TrieNode
}

func sumPrefixScores(words []string) []int {
	root := &TrieNode{
		Val:   -1,
		Score: -1,
	}

	for _, word := range words {
		dummy := root
		for _, r := range word {
			at := int(r - 'a')
			if dummy.Children[at] == nil {
				newNode := &TrieNode{
					Val:   at,
					Score: 1,
				}

				dummy.Children[at] = newNode
			} else {
				dummy.Children[at].Score++
			}

			dummy = dummy.Children[at]
		}
	}

	result := make([]int, len(words))
	for i, word := range words {
		dummy := root
		for _, r := range word {
			at := int(r - 'a')
			result[i] += dummy.Children[at].Score
			dummy = dummy.Children[at]
		}
	}

	return result
}
