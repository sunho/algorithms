package main

import "fmt"

var blocks = [...][2]Cord{
	{{1, 0}, {0, 1}},
	{{1, 0}, {1, 1}},
	{{0, 1}, {1, 1}},
	{{0, 1}, {-1, 1}},
}

type Cord struct {
	x int
	y int
}

func (c Cord) Add(c2 Cord) Cord {
	return Cord{c.x + c2.x, c.y + c2.y}
}

func (c Cord) IsInRange(h int, w int) bool {
	return 0 <= c.y && c.y < h && 0 <= c.x && c.x < w
}

type Board [][]bool

func (b Board) Set(c Cord, t bool) {
	b[c.y][c.x] = t
}

func (b Board) Get(c Cord) bool {
	return b[c.y][c.x]
}

func (b Board) Block(c Cord, block [2]Cord) {
	b.Set(c, true)
	for _, bc := range block {
		b.Set(bc.Add(c), true)
	}
}

func (b Board) Unblock(c Cord, block [2]Cord) {
	b.Set(c, false)
	for _, bc := range block {
		b.Set(bc.Add(c), false)
	}
}

func (b Board) CanBlock(c Cord, block [2]Cord) bool {
	if b.Get(c) {
		return false
	}
	for _, bc := range block {
		bc = bc.Add(c)
		if !bc.IsInRange(len(b), len(b[0])) {
			return false
		}
		if b.Get(bc) {
			return false
		}
	}
	return true
}

func (b Board) IsFull() bool {
	for _, arr := range b {
		for _, t := range arr {
			if !t {
				return false
			}
		}
	}
	return true
}

func Count(board Board, h int, w int) int {
	if board.IsFull() {
		return 1
	}

	var c Cord
L:
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			c = Cord{x, y}
			if !board.Get(c) {
				break L
			}
		}
	}

	var ret int
	for _, block := range blocks {
		if board.CanBlock(c, block) {
			board.Block(c, block)
			ret += Count(board, h, w)
			board.Unblock(c, block)
		}
	}

	return ret
}

func Input() (out Board, h int, w int) {
	fmt.Scanf("%d %d", &h, &w)

	out = make([][]bool, h)

	for i := 0; i < h; i++ {
		var str string
		fmt.Scanf("%s", &str)
		out[i] = make([]bool, 0, w)
		for _, r := range str {
			if r == '#' {
				out[i] = append(out[i], true)
				continue
			}
			if r == '.' {
				out[i] = append(out[i], false)
			}
		}
	}
	return
}

func main() {
	board, h, w := Input()
	fmt.Println(Count(board, h, w))
}
