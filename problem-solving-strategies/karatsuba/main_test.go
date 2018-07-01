package main

import (
	"strconv"
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestMultiply(t *testing.T) {
	a := assert.New(t)
	for i := 0; i < 5000; i++ {
		for j := 0; j < 5000; j++ {
			n, n2 := NewNumber(i), NewNumber(j)
			prd := n.KMultiply(n2)
			sol := i * j
			a.Equal(strconv.Itoa(sol), prd.String())
		}
	}
}
