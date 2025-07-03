package main

import "fmt"
import "strconv"

func getSum(a int, b int) int {
	binaryA := strconv.FormatInt(int64(a), 2)
	binaryB := strconv.FormatInt(int64(b), 2)

	fmt.Println("binary format:", binaryA, binaryB)
	var result string
	hasCarry := false
	lenA, lenB := len(binaryA), len(binaryB)
	idxA, idxB := lenA-1, lenB-1

	for idxA >= 0 || idxB >= 0 {
		oneCount := 0

		intCarry := 0
		if hasCarry {
			oneCount++
			intCarry = 1
		}

		intA := 0
		if idxA >= 0 {
			if int(binaryA[idxA]) == 49 {
				intA = 1
				oneCount++
			}
			idxA--
		}

		intB := 0
		if idxB >= 0 {
			if int(binaryB[idxB]) == 49 {
				intB = 1
				oneCount++
			}
			idxB--
		}

		if oneCount >= 2 {
			hasCarry = true
		} else{
			hasCarry = false
		}

		fmt.Println(intA, intB, intCarry)
		currentDigit := intA ^ intB ^ intCarry
		result = strconv.Itoa(currentDigit) + result
	}
	if hasCarry {
		result = "1" + result
	}

	resultInt64, _ := strconv.ParseInt(result, 2, 64)
	return int(resultInt64)
}

func main() {
	//10, 11
	a, b := -2, 3
	fmt.Println(getSum(a, b))
}
