package main

import "fmt"

type Clock int

func (c *Clock) Next() {
	if *c == 12 {
		*c = 0
	}
	*c += 3
}

type Switch []int

var switches = [10]Switch{
	{0, 1, 2},
	{3, 7, 9, 11},
	{4, 10, 14, 15},
	{0, 4, 5, 6, 7},
	{6, 7, 8, 10, 12},
	{0, 2, 14, 15},
	{3, 14, 15},
	{4, 5, 7, 14, 15},
	{1, 2, 3, 4, 5},
	{3, 4, 5, 9, 13},
}

type Clocks [16]Clock

func (cs *Clocks) On(s Switch) {
	for _, i := range s {
		(*cs)[i].Next()
	}
}

func (cs Clocks) Synced() bool {
	for _, c := range cs {
		if c != 12 {
			return false
		}
	}
	return true
}

const Inf = 5353535353

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func Min(c Clocks, switchindex int) int {
	if c.Synced() {
		return 0
	}
	if switchindex == 10 {
		return Inf
	}

	ret := Inf
	for i := 0; i < 4; i++ {
		ret = min(Min(c, switchindex+1)+i, ret)
		c.On(switches[switchindex])
	}

	return ret
}

func Input() (out Clocks) {
	for i := 0; i < 16; i++ {
		clock := Clock(0)
		fmt.Scanf("%d", &clock)
		out[i] = clock
	}
	return
}

func main() {
	var s int
	fmt.Scanf("%d", &s)
	for i := 0; i < s; i++ {
		clocks := Input()
		ret := Min(clocks, 0)
		if ret == Inf {
			fmt.Println(-1)
			continue
		}
		fmt.Println(ret)
	}
}
