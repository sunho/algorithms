package main

import "fmt"

func gcd(a int, b int) int {
	if a > b {
		return gcd(b, a)
	}
	if a == 0 {
		return b
	}
	return gcd(b%a, a)
}

func main() {
	fmt.Println(gcd(200, 100))
}
