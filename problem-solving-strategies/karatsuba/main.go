package main

import (
	"bytes"
	"fmt"
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
		if n[i] > 9 {
			n[i+1] += int(n[i] / 10)
			n[i] %= 10
		} else if n[i] < 0 {
			borrow := int((n[i]-9)/10) * -1
			n[i+1] -= borrow
			n[i] += borrow * 10
		}
	}

	rem := 0
	for i := len(n) - 1; i >= 1; i-- {
		if n[i] != 0 {
			break
		}
		rem++
	}

	return n[:len(n)-rem]
}

func (n Number) Multiply(n2 Number) Number {
	out := make(Number, len(n)+len(n2)-1, len(n)+len(n2))
	for i := 0; i < len(n); i++ {
		for j := 0; j < len(n2); j++ {
			out[i+j] += n[i] * n2[j]
		}
	}

	return out.Normalize()
}

func (n Number) Clone() Number {
	out := make(Number, len(n), cap(n))
	copy(out, n)
	return out
}

func (n Number) Add(n2 Number) Number {
	if len(n2) > len(n) {
		n, n2 = n2, n
	}

	n = n.Clone()

	for i := 0; i < len(n2); i++ {
		n[i] += n2[i]
	}

	return n
}

func (n Number) AddPos(n2 Number, pos int) {
	if len(n2) > len(n) {
		panic("weired")
	}

	for i := 0; i < len(n2); i++ {
		n[i+pos] += n2[i]
	}
}

func (n Number) Sub(n2 Number) Number {
	more := len(n2) - len(n)
	if more > 0 {
		moren := make(Number, len(n)+more, cap(n)+more)
		copy(moren, n)
		n = moren
	} else {
		n = n.Clone()
	}

	for i := 0; i < len(n2); i++ {
		n[i] -= n2[i]
	}

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

	if len(n)+len(n2) <= 50 {
		return n.Multiply(n2)
	}

	out := make(Number, len(n)+len(n2)-1, len(n)+len(n2)+1)
	half := int(len(n) / 2)
	half2 := min(half, len(n2))

	a1 := n[:half]
	a2 := n[half:]
	b1 := n2[:half2]
	b2 := n2[half2:]

	z1 := a1.KMultiply(b1)
	z3 := a2.KMultiply(b2)
	z2 := a1.Add(a2).Normalize().
		KMultiply(
			b1.Add(b2).Normalize(),
		).
		Sub(z1).
		Sub(z3)

	out = append(out, 0)
	out.AddPos(z1, 0)
	out.AddPos(z2, half)
	out.AddPos(z3, half*2)

	out = out.Normalize()
	return out
}

func (n Number) String() string {
	var buf bytes.Buffer
	for i := len(n) - 1; i >= 0; i-- {
		buf.WriteByte('0' + byte(n[i]))
	}
	if buf.Len() == 0 {
		buf.WriteByte('0')
	}
	return buf.String()
}

func NewNumber(str string) Number {
	out := make(Number, 0, len(str))
	rs := []rune(str)
	for i := len(rs) - 1; i >= 0; i-- {
		out = append(out, int(rs[i]-'0'))
	}
	return out
}

func main() {
	var (
		a string
		b string
	)
	fmt.Scanf("%s %s", a, b)
	fmt.Println(NewNumber(a).KMultiply(NewNumber(b)))
}
