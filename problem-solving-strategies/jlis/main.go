package main

import (
	"fmt"
	"math"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

const NINF = math.MinInt32

func JLIS(a, b []int) int {
	// [a+1][b+1] = max length when the seq ends wiht a,b
	dp := make([][]int, len(a))
	for i := range dp {
		dp[i] = make([]int, len(b))
	}

	for i := 0; i < len(a); i++ {
		for j := 0; j < len(b); j++ {
			piv := max(a[i], b[j])
			for z := i + 1; z < len(a); z++ {
				if a[z] > piv && dp[z][j] < dp[i][j]+1 {
					dp[z][j] = dp[i][j] + 1
				}
			}
			for z := j + 1; z < len(b); z++ {
				if b[z] > piv && dp[i][z] < dp[i][j]+1 {
					dp[i][z] = dp[i][j] + 1
				}
			}
		}
	}

	var ret int
	for i := 0; i < len(a); i++ {
		for j := 0; j < len(b); j++ {
			ret = max(ret, dp[i][j])
		}
	}
	return ret
}

func main() {
	var (
		as int
		bs int
		a  []int
		b  []int
	)
	fmt.Scanf("%d %d", &as, &bs)

	a = make([]int, as+1)
	b = make([]int, bs+1)
	a[0] = NINF
	b[0] = NINF
	for i := 1; i <= as; i++ {
		fmt.Scanf("%d", &a[i])
	}
	for i := 1; i <= bs; i++ {
		fmt.Scanf("%d", &b[i])
	}

	fmt.Println(JLIS(a, b))
}
