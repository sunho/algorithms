package main

import "fmt"

const MOD = 10 * 1000 * 1000

// classify(i,s) = the number of cases for i blocks below s blocks
func Classify(i, s int) int {
	if s == 0 {
		return 1
	}
	return i + s - 1
}

// n = remaining block s = last number of blocks
// count(n,s) = sum(for i <- 1 to n count(n-i,i) * classify(i,s)
// dp[n][s]
func Count(n int) int {
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
		for j := range dp[i] {
			if i == 0 {
				dp[i][j] = 1
			}
		}
	}

	// i = n
	// j = s
	// z = i
	for i := 0; i <= n; i++ {
		for j := 0; j <= n; j++ {
			for z := 1; z <= i; z++ {
				dp[i][j] = (dp[i][j] + dp[i-z][z]*Classify(z, j)) % MOD
			}
		}
	}

	return dp[n][0]
}

func main() {
	var s int
	fmt.Scanf("%d", &s)
	for i := 0; i < s; i++ {
		var d int
		fmt.Scanf("%d", &d)
		fmt.Println(Count(d))
	}
}
