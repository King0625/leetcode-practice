package leetcode

import "strings"

func simplifyPath(path string) string {
    basePath := "/"

	locations := strings.Split(path, "/")

	var stack []string
	var stackSize int

	for _, location := range locations {
		if location == "" || location == "." {
			continue
		} else if location == ".." {
			stackSize = len(stack)
			if stackSize == 0 {
				continue
			}
			stack = stack[:stackSize-1]
		} else {
			stack = append(stack, location)
		}
	}

	result := strings.Join(stack, "/")

	return basePath + result
}

