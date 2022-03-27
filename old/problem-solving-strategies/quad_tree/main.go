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
		return "i"
	}
}

func main() {
	var s int
	fmt.Scanf("%d", &s)
	for i := 0; i < s; i++ {
		str := ""
		fmt.Scanf("%s", &str)
		arr := []rune(str)
		fmt.Println(Reverse(&arr))
	}
}
