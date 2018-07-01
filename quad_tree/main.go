package main

import "fmt"

func Reverse(arr *[]rune) string {
	if len(*arr) == 0 {
		return ""
	}
	c := (*arr)[0]
	*arr = (*arr)[1:]
	switch c {
	case 'w':
		return "w"
	case 'b':
		return "b"
	case 'x':
		a, b, c, d := Reverse(arr), Reverse(arr), Reverse(arr), Reverse(arr)
		return "x" + c + d + a + b
	default:
		panic("invailid character")
	}
}

func main() {
	str := ""
	fmt.Scanf("%s", &str)
	arr := []rune(str)
	fmt.Println(Reverse(&arr))
}
