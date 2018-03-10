package main

import (
	"fmt"
)

func main() {
	c := 0.0
	_, err := fmt.Scanf("%f", &c)
	if err != nil {
		fmt.Println("asdasdsadas")
	}
	fmt.Println(c)
}
