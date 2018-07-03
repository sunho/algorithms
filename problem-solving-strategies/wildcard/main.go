package main

import "fmt"

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
	if si == len(str) && pi == len(pat)-1 && pat[0] == '*' {
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

func main() {
	var (
		pat_ string
		str_ string
	)
	fmt.Scanf("%s %s", &pat_, &str_)
	pat := []rune(pat_)
	str := []rune(str_)
	InitMemory(len(pat), len(str))
	fmt.Println(Check(0, []rune(pat), 0, []rune(str)))
}
