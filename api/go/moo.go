package moo

/*
#cgo LDFLAGS: -lmoo
#include <stdint.h>
#include <stdlib.h>

double absolute(double x);
int64_t idiv(double a, double b);
int64_t dfloor(double a);
int64_t dceil(double a);
int64_t gcd(int64_t a, int64_t b);
int64_t lcm(int64_t a, int64_t b);
int64_t mod(int64_t a, int64_t b);
double flmod(double a, double b);
int64_t fac(int64_t n);
int64_t binom(int64_t n, int64_t k);
int64_t* factable(int64_t n);
void clearptr(int64_t* ptr);
int64_t permutation(int n, int k);
int64_t combination(int n, int k);
int64_t* genPerm(int64_t n);
void freeptr(int64_t* ptr);
double max(double a, double b);
double min(double a, double b);
*/
import "C"
import (
	"errors"
	"unsafe"
)

type Moo struct{}

func (Moo) Abs(x float64) float64 {
	return float64(C.absolute(C.double(x)))
}

func (Moo) IDiv(a, b float64) int64 {
	return int64(C.idiv(C.double(a), C.double(b)))
}

func (Moo) Floor(a float64) int64 {
	return int64(C.dfloor(C.double(a)))
}

func (Moo) Ceil(a float64) int64 {
	return int64(C.dceil(C.double(a)))
}

func (Moo) GCD(a, b int64) int64 {
	return int64(C.gcd(C.int64_t(a), C.int64_t(b)))
}

func (Moo) LCM(a, b int64) int64 {
	return int64(C.lcm(C.int64_t(a), C.int64_t(b)))
}

func (Moo) Mod(a, b int64) int64 {
	return int64(C.mod(C.int64_t(a), C.int64_t(b)))
}

func (Moo) FlMod(a, b float64) float64 {
	return float64(C.flmod(C.double(a), C.double(b)))
}

func (Moo) Fac(n int64) int64 {
	return int64(C.fac(C.int64_t(n)))
}

func (Moo) Binom(n, k int64) int64 {
	return int64(C.binom(C.int64_t(n), C.int64_t(k)))
}

func (Moo) Factable(n int64) ([]int64, error) {
	if n <= 0 {
		return nil, errors.New("n cannot be 0")
	}
	ptr := C.factable(C.int64_t(n))
	if ptr == nil {
		return nil, errors.New("NULL pointer returned from factable function")
	}
	defer C.clearptr(ptr)
	slice := unsafe.Slice((*int64)(unsafe.Pointer(ptr)), n+1)
	result := make([]int64, n+1)
	copy(result, slice)
	return result, nil
}

func (Moo) Permutation(n, k int) int64 {
	return int64(C.permutation(C.int(n), C.int(k)))
}

func (Moo) Combination(n, k int) int64 {
	return int64(C.combination(C.int(n), C.int(k)))
}

func (Moo) GenPerm(n int64) ([][]int64, error) {
	if n <= 0 {
		return nil, errors.New("n cannot be 0")
	}
	ptr := C.genPerm(C.int64_t(n))
	if ptr == nil {
		return nil, errors.New("NULL pointer returned from genPerm function")
	}
	defer C.freeptr(ptr)
	total := int64(1)
	for i := int64(1); i <= n; i++ {
		total *= i
	}
	slice := unsafe.Slice((*int64)(unsafe.Pointer(ptr)), total*n)
	result := make([][]int64, total)
	for i := int64(0); i < total; i++ {
		result[i] = make([]int64, n)
		copy(result[i], slice[i*n:(i+1)*n])
	}
	return result, nil
}

func (Moo) Max(a, b float64) float64 {
	return float64(C.max(C.double(a), C.double(b)))
}

func (Moo) Min(a, b float64) float64 {
	return float64(C.min(C.double(a), C.double(b)))
}