package main

import (
	"fmt"
	"sort"
	"strings"
)

//[pi][si] -> res
var memory [][]int

func InitMemory(psize, ssize int) {
	memory = make([][]int, psize)
	for i := range memory {
		memory[i] = make([]int, ssize)
	}
}

func GetMemory(pi, si int) (res bool, exist bool) {
	if memory[pi][si] == 0 {
		return false, false
	}
	return memory[pi][si] == 2, true
}

func SetMemory(pi int, si int, res bool) {
	if res {
		memory[pi][si] = 2
		return
	}
	memory[pi][si] = 1
}

func Check(pi int, pat []rune, si int, str []rune) bool {
	if si == len(str) && pi == len(pat) {
		return true
	}
	if si == len(str) && pi == len(pat)-1 && pat[pi] == '*' {
		return true
	}
	if pi == len(pat) || si == len(str) {
		return false
	}
	if res, exist := GetMemory(pi, si); exist {
		return res
	}

	var res bool

	switch pat[pi] {
	case '*':
		// capture or not
		res = Check(pi, pat, si+1, str) ||
			Check(pi+1, pat, si, str)
	case '?':
		res = Check(pi+1, pat, si+1, str)
	default:
		if pat[pi] != str[si] {
			res = false
			break
		}
		res = Check(pi+1, pat, si+1, str)
	}

	SetMemory(pi, si, res)

	return res
}

func InputString() []rune {
	var str string
	fmt.Scanf("%s", &str)
	return []rune(str)
}

func main() {
	var s int
	fmt.Scanf("%d", &s)
	for i := 0; i < s; i++ {
		var d int

		pat := InputString()
		fmt.Scanf("%d", &d)
		strs := make([]string, 0, d)
		for j := 0; j < d; j++ {
			str := InputString()
			InitMemory(len(pat), len(str))
			if Check(0, pat, 0, str) {
				strs = append(strs, string(str))
			}
		}

		sort.Strings(strs)
		fmt.Println(strings.Join(strs, "\n"))
	}
}
