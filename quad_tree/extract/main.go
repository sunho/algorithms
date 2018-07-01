package main

import "fmt"

type Board [][]bool

func NewBoard(size int) Board {
	out := make(Board, size)
	for i := range out {
		out[i] = make([]bool, size)
	}
	return out
}

func (b Board) Fill(p bool, x int, y int, size int) {
	for i := 0; i < size; i++ {
		for j := 0; j < size; j++ {
			b[i+y][j+x] = p
		}
	}
}

func Extract(arr *[]rune, board Board, x int, y int, size int) {
	if len(*arr) == 0 {
		return
	}
	c := (*arr)[0]
	*arr = (*arr)[1:]
	switch c {
	case 'w':
	case 'b':
		board.Fill(true, x, y, size)
	case 'x':
		Extract(arr, board, x, y, size/2)
		Extract(arr, board, x+size/2, y, size/2)
		Extract(arr, board, x, y+size/2, size/2)
		Extract(arr, board, x+size/2, y+size/2, size/2)
	default:
		panic("invailid character")
	}
}

func main() {
	str := ""
	fmt.Scanf("%s", &str)
	arr := []rune(str)
	board := NewBoard(32)
	Extract(&arr, board, 0, 0, 32)
	for _, i := range board {
		for _, j := range i {
			if j == true {
				fmt.Print("#")
			} else {
				fmt.Print("0")
			}
		}
		fmt.Print("\n")
	}
}
