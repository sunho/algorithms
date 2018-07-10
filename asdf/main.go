package main

import (
	"fmt"
)

func asd() {
	panic(nil)
}

func main() {
	defer fmt.Println("asdf")
	asd()
}
