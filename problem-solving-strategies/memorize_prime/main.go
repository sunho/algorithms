package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"strconv"
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

func ReadInt(bio *bufio.Reader) int {
	line, err := bio.ReadString('\n')
	if err != nil && err != io.EOF {
		panic(err)
	}
	line = line[:len(line)-1]
	num, err := strconv.Atoi(line)
	if err != nil {
		panic(err)
	}
	return num
}

func main() {
	bio := bufio.NewReader(os.Stdin)
	s := ReadInt(bio)
	for z := 0; z < s; z++ {
		buf, err := bio.ReadBytes('\n')
		if err != nil {
			panic(err)
		}
		buf = buf[:len(buf)-1]
		n := make([]int, len(buf)+1)
		for i := range buf {
			n[i+1] = int(buf[i] - '0')
		}
		fmt.Println(Memorize(n))
	}
}
