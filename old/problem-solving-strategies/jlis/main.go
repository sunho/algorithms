package main

import (
	"bufio"
	"io"
	"math"
	"os"
	"strconv"
	"strings"
)

func max64(a, b int64) int64 {
	if a > b {
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

const NINF = math.MinInt32 - 1

//https://algospot.com/judge/submission/detail/201129
func ReadLine(bio *bufio.Reader) []int64 {
	line, err := bio.ReadString('\n')
	if err != nil && err != io.EOF {
		panic(err)
	}
	nums := strings.Fields(line)
	ret := make([]int64, len(nums)+1)
	for i, num := range nums {
		ret[i+1], _ = strconv.ParseInt(num, 10, 64)
	}
	return ret
}

func main() {
	var (
		s   int
		as  int
		bs  int
		ret int
		a   []int64
		b   []int64
		dp  [101][101]int
		br  = bufio.NewReader(os.Stdin)
		bw  = bufio.NewWriter(os.Stdout)
	)
	s = int(ReadLine(br)[1])
	for k := 0; k < s; k++ {
		buf := ReadLine(br)
		as, bs = int(buf[1]), int(buf[2])

		a = ReadLine(br)
		b = ReadLine(br)
		a[0] = NINF
		b[0] = NINF

		// [a+1][b+1] = max length when the seq ends wiht a,b
		for i := 0; i <= as; i++ {
			for j := 0; j <= bs; j++ {
				dp[i][j] = 0
			}
		}

		ret = 0
		for i := 0; i <= as; i++ {
			for j := 0; j <= bs; j++ {
				piv := max64(a[i], b[j])
				for z := i + 1; z <= as; z++ {
					if a[z] > piv && dp[z][j] < dp[i][j]+1 {
						dp[z][j] = dp[i][j] + 1
						ret = max(ret, dp[z][j])
					}
				}
				for z := j + 1; z <= bs; z++ {
					if b[z] > piv && dp[i][z] < dp[i][j]+1 {
						dp[i][z] = dp[i][j] + 1
						ret = max(ret, dp[i][z])
					}
				}
			}
		}
		bw.Write([]byte(strconv.Itoa(ret)))
		bw.WriteByte('\n')
	}
	bw.Flush()
}
