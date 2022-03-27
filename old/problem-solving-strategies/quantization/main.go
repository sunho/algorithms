package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
)

const Inf = math.MaxInt32

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// sigma(a[i]-m)^2 = sigma(a[i]^2) - 2m*sigma(a[i]) + sigma(m^2)
func Sum(ps []int, pss []int, n []int, lo int, hi int) int {
	sum := ps[hi] - ps[lo] + n[lo]
	ssum := pss[hi] - pss[lo] + n[lo]*n[lo]
	wide := (hi - lo + 1)
	m := int(float64(sum)/float64(wide) + 0.5)
	return ssum - 2*m*sum + m*m*wide
}

// quantize(i,j) = min(for z = i+1 to len(n)-1 quantize(z, j-1) + sum(i, z-1))
// dp[i][j] = the minimun when starts from i(j is s)
func Quntize(n []int, s int) int {
	sort.Ints(n)

	ps := make([]int, len(n))
	ps[0] = n[0]
	for i := 1; i < len(n); i++ {
		ps[i] = ps[i-1] + n[i]
	}

	pss := make([]int, len(n))
	pss[0] = n[0] * n[0]
	for i := 1; i < len(n); i++ {
		pss[i] = pss[i-1] + n[i]*n[i]
	}

	dp := make([][]int, len(n))
	for i := range dp {
		dp[i] = make([]int, s)
		for j := range dp[i] {
			if j != 0 {
				dp[i][j] = Inf
				continue
			}
			dp[i][j] = Sum(ps, pss, n, i, len(n)-1)
		}
	}

	for j := 1; j < s; j++ {
		for i := 0; i < len(n); i++ {
			for z := i + 1; z <= len(n); z++ {
				if z == len(n) {
					dp[i][j] = min(Sum(ps, pss, n, i, z-1), dp[i][j])
					continue
				}
				dp[i][j] = min(dp[z][j-1]+Sum(ps, pss, n, i, z-1), dp[i][j])
			}
		}
	}

	return dp[0][s-1]
}

func ReadLine(bio *bufio.Reader) []int {
	line, err := bio.ReadString('\n')
	if err != nil {
		panic(err)
	}
	line = line[:len(line)-1]
	words := strings.Fields(line)
	out := make([]int, 0, len(words))
	for _, word := range words {
		d, err := strconv.Atoi(word)
		if err != nil {
			panic(err)
		}
		out = append(out, d)
	}
	return out
}

func main() {
	bio := bufio.NewReader(os.Stdin)
	c := ReadLine(bio)[0]
	for c != 0 {
		c--
		buf := ReadLine(bio)
		s := buf[1]
		n := ReadLine(bio)
		fmt.Println(Quntize(n, s))
	}
}
