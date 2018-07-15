package main

import "fmt"

type Block [2]Cord

var blocks = [...]Block{
	{{0, 1}, {1, 0}},
	{{0, 1}, {1, 1}},
	{{1, 0}, {1, 1}},
	{{1, 0}, {1, -1}},
}

type Cord struct {
	y int
	x int
}

func (c Cord) Add(c2 Cord) Cord {
	return Cord{c.y + c2.y, c.x + c2.x}
}

type Board [][]bool

func (b Board) Width() int {
	return len(b[0])
}

func (b Board) Height() int {
	return len(b)
}

func (b Board) IsInRange(c Cord) bool {
	return 0 <= c.y && c.y < b.Height() && 0 <= c.x && c.x < b.Width()
}

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
		if !b.IsInRange(bc) {
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

func Count(board Board) int {
	if board.IsFull() {
		return 1
	}

	var c Cord
L:
	for y := 0; y < board.Height(); y++ {
		for x := 0; x < board.Width(); x++ {
			c = Cord{y, x}
			if !board.Get(c) {
				break L
			}
		}
	}

	var ret int
	for _, block := range blocks {
		if board.CanBlock(c, block) {
			board.Block(c, block)
			ret += Count(board)
			board.Unblock(c, block)
		}
	}

	return ret
}

func Input() (out Board) {
	var (
		h int
		w int
	)

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
	var s int
	fmt.Scanf("%d", &s)
	for i := 0; i < s; i++ {
		board := Input()
		fmt.Println(Count(board))
	}
}
