package main

import "strconv"

func evalRPN(tokens []string) int {
	var stack []int

	for _, token := range tokens {
		if val, err := strconv.Atoi(token); err == nil {
			stack = append(stack, val)
		} else {
			secondNum := stack[len(stack)-1]
			firstNum := stack[len(stack)-2]
			stack = stack[:len(stack)-2]
			var result int
			switch token {
			case "+":
				result = firstNum + secondNum
			case "-":
				result = firstNum - secondNum
			case "*":
				result = firstNum * secondNum
			case "/":
				result = firstNum / secondNum
			}

			stack = append(stack, result)
		}
	}

	return stack[0]
}
