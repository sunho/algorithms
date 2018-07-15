package main

import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

// f(n,d) = sum(for i := every town 1/len(i's town) * f(i,d-1))
func Calculate(town [][]int, start int, d int) []float64 {
	dp := make([][]float64, d+1)
	for i := range dp {
		dp[i] = make([]float64, len(town))
	}
	dp[0][start] = 1
	for i := 0; i < d; i++ {
		for j := 0; j < len(town); j++ {
			if dp[i][j] == 0 {
				continue
			}
			for z := 0; z < len(town[j]); z++ {
				to := town[j][z]
				dp[i+1][to] += 1 / float64(len(town[j])) * dp[i][j]
			}
		}
	}

	return dp[d]
}

func ReadBianryLine(bio *bufio.Reader) []int {
	line, err := bio.ReadString('\n')
	if err != nil {
		panic(err)
	}
	line = line[:len(line)-1]
	words := strings.Fields(line)
	out := make([]int, 0, len(words))
	for i, word := range words {
		if word[0] == '1' {
			out = append(out, i)
		} else if word[0] != '0' {
			panic("")
		}
	}
	return out
}

func ReadNumberLine(bio *bufio.Reader) []int {
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
	bw := bufio.NewWriter(os.Stdout)
	s := ReadNumberLine(bio)[0]
	for s != 0 {
		s--
		buf := ReadNumberLine(bio)
		n, d, p := buf[0], buf[1], buf[2]
		town := make([][]int, n)
		for i := 0; i < n; i++ {
			town[i] = ReadBianryLine(bio)
		}

		prob := Calculate(town, p, d)
		n = ReadNumberLine(bio)[0]
		buf = ReadNumberLine(bio)
		for i, t := range buf {
			bw.WriteString(strconv.FormatFloat(prob[t], 'f', 8, 64))
			if i != n-1 {
				bw.WriteByte(' ')
			} else {
				bw.WriteByte('\n')
			}
		}
	}
	bw.Flush()
}
