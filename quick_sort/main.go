package main

import "fmt"

func QuickSort(arr []int) []int {
	if len(arr) <= 1 {
		return arr
	}

	less := make([]int, 0, len(arr)/2)
	piv := arr[0]
	more := make([]int, 0, len(arr)/2)

	for _, n := range arr[1:] {
		if n >= piv {
			more = append(more, n)
		} else {
			less = append(less, n)
		}
	}

	out := make([]int, 0, len(arr))
	out = append(out, QuickSort(less)...)
	out = append(out, piv)
	out = append(out, QuickSort(more)...)

	return out
}

func main() {
	arr := []int{5, 3, 2, 10, 1, 4, 1, 5, 2, 4}
	fmt.Println(QuickSort(arr))
	return
}
