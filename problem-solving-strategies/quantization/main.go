package main

import (
	"fmt"
	"math"
	"sort"
)

const Inf = math.MaxInt32

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// can be omptimized drastically
func Sum(n []int) int {
	var s int
	for _, a := range n {
		s += a
	}
	avg := int(math.Round(float64(s) / float64(len(n))))

	var out int
	for _, a := range n {
		out += (a - avg) * (a - avg)
	}

	return out
}

// quantize(i,s) = min(for t = i+1 to len(n)-1 quantize(t, s-1) + sum(i, t-1))
// dp[s][x] = the minimun when starts from x
// dp[][len(n)] means empty sequences
func Quntize(n []int, s int) int {
	sort.Ints(n)
	dp := make([][]int, s)
	for i := range dp {
		dp[i] = make([]int, len(n)+1)
		for j := range dp[i] {
			if i != s-1 {
				dp[i][j] = Inf
				continue
			}
			if j == len(n) {
				dp[i][j] = 0
				continue
			}
			dp[i][j] = Sum(n[j:len(n)])
		}
	}

	for i := s - 1; i > 0; i-- {
		for j := len(n); j > 0; j-- {
			for z := 1; z <= j; z++ {
				dp[i-1][j-z] = min(dp[i][j]+Sum(n[j-z:j]), dp[i-1][j-z])
			}
		}
	}

	return dp[0][0]
}

func main() {
	var (
		ns int
		s  int
	)
	fmt.Scanf("%d %d", &ns, &s)
	n := make([]int, ns)
	for i := 0; i < ns; i++ {
		fmt.Scanf("%d", &n[i])
	}

	fmt.Println(Quntize(n, s))
}
