package main

import (
	"fmt"
	"time"
)

func newMultiply(x int, y int) int {
	if y == 0 {
		return 0
	}
	if y%2 == 0 {
		return newMultiply(x<<1, y>>1)
	}
	return x + newMultiply(x<<1, y>>1)
}

func main() {
	t := time.Now()
	for i := 0; i < 100; i++ {
		for j := 0; j < 100; j++ {
			fmt.Println(newMultiply(i, j))
		}
	}
	m1 := time.Now().Sub(t).Nanoseconds()
	t = time.Now()
	for i := 0; i < 100; i++ {
		for j := 0; j < 100; j++ {
			fmt.Println(i * j)
		}
	}
	m2 := time.Now().Sub(t).Nanoseconds()
	fmt.Println("implemented")
	fmt.Println(m1)
	fmt.Println("builtin")
	fmt.Println(m2)
	fmt.Println(m2 - m1)
}
