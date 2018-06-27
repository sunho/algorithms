package main

import "fmt"

func MergeSort(arr []int) []int {
	pivot := int(len(arr) / 2)
	if pivot == 0 {
		return arr
	}

	return Merge(
		MergeSort(arr[:pivot]),
		MergeSort(arr[pivot:len(arr)]),
	)
}

func Merge(arr1 []int, arr2 []int) []int {
	out := make([]int, 0, len(arr1)+len(arr2))
	i, j := 0, 0
	for i < len(arr1) || j < len(arr2) {
		if len(arr2) == j {
			out = append(out, arr1[i])
			i++
		} else if len(arr1) == i {
			out = append(out, arr2[j])
			j++
		} else if arr1[i] < arr2[j] {
			out = append(out, arr1[i])
			i++
		} else {
			out = append(out, arr2[j])
			j++
		}
	}
	return out
}

func main() {
	arr := []int{10, 9, 8, 4, 3, 2, 5, 2, 4, 1}
	fmt.Println(MergeSort(arr))
}
