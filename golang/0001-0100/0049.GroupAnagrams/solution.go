package leetcode

import "slices"

func groupAnagrams(strs []string) [][]string {
	groups := make(map[string][]int)

	for i, str := range strs {
		var runes []rune

		for _, r := range str {
			runes = append(runes, r)
		}

		slices.Sort(runes)

		sortedStr := string(runes)

		if _, ok := groups[sortedStr]; !ok {
			groups[sortedStr] = []int{i}
		} else {
			groups[sortedStr] = append(groups[sortedStr], i)
		}
	}

	var result [][]string

	for _, v := range groups {
        var group []string
        for _, idx := range v {
            group = append(group, strs[idx])
        }
		result = append(result, group)
	}

	return result
}

