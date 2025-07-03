package main

import "fmt"

func checkNeighbor(board [][]int, x, y int) {

}

func gameOfLife(board [][]int) {

}

func main() {
	board := [][]int{
		{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0},
	}

	gameOfLife(board)

	fmt.Println(board)
}
