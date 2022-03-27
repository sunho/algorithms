package main

import "fmt"

var total int

func smallest(arr []int) int {
	if len(arr) == 0 {
		return 0
	}

	return arr[len(arr)-1] + 1
}

func pick(n int, arr []int, toPick int) {
	if toPick == 0 {
		total++
		fmt.Println(arr)
		return
	}

	for i := smallest(arr); i < n; i++ {
		arr = append(arr, i)
		pick(n, arr, toPick-1)
		arr = arr[:len(arr)-1]
	}
}

func main() {
	pick(10, []int{}, 10)
	fmt.Printf("total: %d\n", total)
}
