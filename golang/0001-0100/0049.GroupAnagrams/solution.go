package leetcode

import "slices"

func groupAnagrams(strs []string) [][]string {
	groups := make(map[string][]string)

	for _, str := range strs {
		var runes []rune

		for _, r := range str {
			runes = append(runes, r)
		}
		
		slices.Sort(runes)

		sortedStr := string(runes)

		if _, ok := groups[sortedStr]; !ok {
			groups[sortedStr] = []string{str}
		} else {
			groups[sortedStr] = append(groups[sortedStr], str)
		}
	}

	var result [][]string

	for _, v := range groups {
		result = append(result, v)
	}

	return result
}

