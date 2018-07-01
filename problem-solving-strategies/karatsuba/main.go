package main

import (
	"fmt"
	"strconv"
)

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

type Number []int

func (n Number) Normalize() Number {
	n = append(n, 0)
	for i := 0; i < len(n)-1; i++ {
		if n[i] >= 0 {
			n[i+1] += int(n[i] / 10)
			n[i] %= 10
		} else {
			borrow := int((n[i]-9)/10) * -1
			n[i+1] -= borrow
			n[i] += borrow * 10
		}
	}

	rem := 0
	for i := len(n) - 1; i >= 0; i-- {
		if n[i] != 0 {
			break
		}
		rem++
	}
	return n[:len(n)-rem]
}

func (n Number) Multiply(n2 Number) Number {
	out := make(Number, len(n)+len(n2)-1)
	for i := 0; i < len(n); i++ {
		for j := 0; j < len(n2); j++ {
			out[i+j] += n[i] * n2[j]
		}
	}
	out = out.Normalize()
	return out
}

func (n Number) Add(n2 Number, pos int) Number {
	if len(n2) > len(n) {
		n, n2 = n2, n
	}

	for i := 0; i < len(n2); i++ {
		n[i+pos] += n2[i]
	}
	n = n.Normalize()
	return n
}

func (n Number) Sub(n2 Number, pos int) Number {
	more := len(n2) - len(n)
	if more > 0 {
		mores := make(Number, more)
		n = append(n, mores...)
	}

	for i := 0; i < len(n2); i++ {
		n[i+pos] -= n2[i]
	}

	n = n.Normalize()
	return n
}

// (a1+a2*10^n)*(b1+b2*10^n) = a1*b1 + 10^n*(a1*b2+a2*b1) + a2*b2*10^2n
// (a1+a2)*(b1+b2) = a1*b1 + a1*b2 + a2*b1 + a2*b2
// z1 = a1*b1 z2 = a1*b2 + a2*b1 z3 = a2*b2
// z2 = (a1+a2)*(b1+b2) - z1 -z3
func (n Number) KMultiply(n2 Number) Number {
	if len(n) == 0 || len(n2) == 0 {
		return nil
	}

	out := make(Number, len(n)+len(n2)-1)
	if len(out) <= 50 {
		return n.Multiply(n2)
	}

	half := int(len(n) / 2)
	half2 := min(half, len(n2))

	a1 := n[:half]
	a2 := n[half:]
	b1 := n2[:half2]
	b2 := n2[half2:]

	z1 := a1.KMultiply(b1)
	z3 := a2.KMultiply(b2)
	z2 := a1.Add(a2, 0).KMultiply(b1.Add(b2, 0)).Sub(z1, 0).Sub(z3, 0)

	out.Add(z1, 0)
	out.Add(z2, half)
	out.Add(z3, half*2)

	return out
}

func (n Number) String() string {
	out := ""
	for i := len(n) - 1; i >= 0; i-- {
		out += strconv.Itoa(n[i])
	}

	if out == "" {
		return "0"
	}
	return out
}

func NewNumber(d int) Number {
	out := Number{}
	for d != 0 {
		out = append(out, d%10)
		d /= 10
	}
	return out
}

func Input() Number {
	var d int
	fmt.Scanf("%d", &d)

	return NewNumber(d)
}

func main() {
	a, b := Input(), Input()
	c := a.KMultiply(b)
	fmt.Println(c)
}
