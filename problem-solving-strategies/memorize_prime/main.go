package main

import (
	"fmt"
	"math"
)

const Inf = math.MaxInt32

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func abs(n int) int {
	if n < 0 {
		return n * -1
	}
	return n
}

func Classify(n []int) int {
	var (
		d        = n[1] - n[0]
		progress = true
		alter    = true
	)

	for i := 2; i < len(n); i++ {
		if d != n[i]-n[i-1] {
			progress = false
		}
		if n[i] != n[i-2] {
			alter = false
		}
	}

	if progress && d == 0 {
		return 1
	}
	if progress && abs(d) == 1 {
		return 2
	}
	if alter {
		return 4
	}
	if progress {
		return 5
	}

	return 10
}

func Memorize(n []int) int {
	dp := make([]int, len(n))
	for i := 1; i < len(n); i++ {
		dp[i] = Inf
	}

	for i := 3; i < len(dp); i++ {
		for j := 3; j <= 5; j++ {
			prev := i - j
			if prev == 0 || prev >= 3 {
				dp[i] = min(dp[prev]+Classify(n[prev+1:i+1]), dp[i])
			}
		}
	}

	return dp[len(dp)-1]
}

func main() {
	var str string
	fmt.Scanf("%s", &str)
	n := make([]int, len(str)+1)

	buf := []byte(str)
	for i := range buf {
		n[i+1] = int(str[i] - '0')
	}

	fmt.Println(Memorize(n))
}
