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
			switch token {
			case "+":
				stack = append(stack, firstNum+secondNum)
			case "-":
				stack = append(stack, firstNum-secondNum)
			case "*":
				stack = append(stack, firstNum*secondNum)
			case "/":
				stack = append(stack, firstNum/secondNum)
			}
		}
	}

	return stack[0]
}
