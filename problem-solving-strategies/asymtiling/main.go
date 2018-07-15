package main

import (
	"fmt"
)

const N = 1000000007

func MemoryCount(n int) int {
	memory := make([][][]int, n+1)
	for i := range memory {
		memory[i] = make([][]int, n+1)
		for j := range memory[i] {
			memory[i][j] = make([]int, 2)
			for z := range memory[i][j] {
				memory[i][j][z] = -1
			}
		}
	}
	return Count(memory, 0, n, 1)
}

func Count(memory [][][]int, x int, y int, same int) int {
	if same == 0 {
		switch y - x {
		case 0:
			return 1
		case 1:
			return 1
		case 2:
			return 2
		}
	}

	if memory[x][y][same] != -1 {
		return memory[x][y][same]
	}

	res := 0
	if y-x >= 4 {
		res = (res + Count(memory, x+2, y-2, same)) % N
	}
	if y-x >= 3 {
		res = (res + Count(memory, x+1, y-2, 0)) % N
		res = (res + Count(memory, x+2, y-1, 0)) % N
	}
	if y-x >= 2 {
		res = (res + Count(memory, x+1, y-1, same)) % N
	}

	memory[x][y][same] = res

	return res
}

func main() {
	s := 0
	fmt.Scanf("%d", &s)
	for s != 0 {
		s--
		n := 0
		fmt.Scanf("%d", &n)
		fmt.Println(MemoryCount(n))
	}
}
