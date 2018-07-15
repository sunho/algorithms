package main

import "fmt"

type Boards []int

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func (b Boards) GetWidestOverlap(i, j int) int {
	var (
		width = 0
		n     = min(b[i], b[j])
	)

	for i >= 0 || j < len(b) {
		for i >= 0 && n <= b[i] {
			i--
		}
		for j < len(b) && n <= b[j] {
			j++
		}

		width = max(width, (j-i-1)*n)

		iin := i != -1
		jin := j != len(b)
		if iin && jin {
			n = min(n, max(b[i], b[j]))
			continue
		}
		if iin {
			n = min(n, b[i])
		}
		if jin {
			n = min(n, b[j])
		}
	}

	return width
}

func GetWidest(boards Boards) int {
	if len(boards) == 1 {
		return boards[0]
	}

	half := int(len(boards) / 2)
	left := GetWidest(boards[:half])
	right := GetWidest(boards[half:])
	middle := boards.GetWidestOverlap(half-1, half)

	return max(max(left, right), middle)
}

func Input() Boards {
	n := 0
	fmt.Scanf("%d", &n)

	out := make(Boards, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &out[i])
	}
	return out
}

func main() {
	var s int
	fmt.Scanf("%d", &s)
	for i := 0; i < s; i++ {
		boards := Input()
		fmt.Println(GetWidest(boards))
	}
}
