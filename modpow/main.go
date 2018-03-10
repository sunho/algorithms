package main

import "fmt"

func modpow(x int, y int, n int) int {
	if y == 0 {
		return 1
	}
	z := modpow(x, y>>1, n)
	if y%2 == 1 {
		return x * z * z % n
	}
	return z * z % n
}

func main() {
	fmt.Println(modpow(10, 4, 1000000))
}
