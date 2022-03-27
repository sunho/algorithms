package main

import (
	"strings"
	"testing"
)

func TestCheckBench(t *testing.T) {
	pat := []rune(strings.Repeat("*", 100))
	str := []rune(strings.Repeat("s", 100))
	for i := 0; i < 10000; i++ {
		InitMemory(len(pat), len(str))
		if Check(0, pat, 0, str) == false {
			t.Error("this should be true")
		}
	}
}
