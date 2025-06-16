package leetcode

func isValid(s string) bool {
	var stack []rune
	for i := 0; i < len(s); i++ {
		r := rune(s[i])
		stackSize := len(stack)
		switch r {
		case '(', '{', '[':
			stack = append(stack, r)
		case ')':
			if stackSize == 0 || stack[stackSize-1] != '(' {
				return false
			}
			stack = stack[:stackSize-1]
		case '}':
			if stackSize == 0 || stack[stackSize-1] != '{' {
				return false
			}
			stack = stack[:stackSize-1]
		case ']':
			if stackSize == 0 || stack[stackSize-1] != '[' {
				return false
			}
			stack = stack[:stackSize-1]
		}
	}

	return len(stack) == 0
}

