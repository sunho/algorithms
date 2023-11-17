use std::cell::UnsafeCell;
use std::io::{stdin, BufWriter, Read, Stdin, Stdout};
use std::str::FromStr;
use std::{cmp::*, collections::*, iter, mem::*, num::*, ops::*};

fn solve() {
    let a = read!(String);
}

const IO_BUF_SIZE: usize = 1 << 16;
type Input = Scanner<Stdin>;
fn _init_input() -> Input {
    Scanner::new(std::io::stdin())
}

#[repr(transparent)]
struct Unsync<T>(T);
unsafe impl<T> Sync for Unsync<T> {}

type BadLazy<T> = Unsync<UnsafeCell<Option<T>>>;
impl<T> BadLazy<T> {
    const fn new() -> Self {
        Self(UnsafeCell::new(None))
    }
}

static INPUT: BadLazy<Input> = BadLazy::new();

fn inp<F: FnOnce(&mut Input) -> R, R>(f: F) -> R {
    unsafe { f((&mut *INPUT.0.get()).get_or_insert_with(_init_input)) }
}

macro_rules! read {
    () => { read() };
    ($t: ty) => { read::<$t>() };
    ($t: ty, $($tt: ty),*) => { (read::<$t>(), $(read::<$tt>(),)*) };
    [$t: ty; $n: expr] => { read_vec::<$t>($n) };
}

fn input_is_eof() -> bool {
    inp(|x| x.eof())
}
fn read_byte() -> u8 {
    inp(|x| x.byte())
}
fn read_bytes_no_skip(n: usize) -> Vec<u8> {
    inp(|x| x.bytes_no_skip(n))
}
fn read_bytes(n: usize) -> Vec<u8> {
    inp(|x| x.bytes(n))
}
fn read_bytes2(n: usize, m: usize) -> Vec<Vec<u8>> {
    inp(|x| x.bytes2(n, m))
}
fn read_token() -> Vec<u8> {
    inp(|x| x.token_bytes())
}
fn read_token_str() -> String {
    unsafe { String::from_utf8_unchecked(read_token()) }
}
fn read_line() -> Vec<u8> {
    inp(|x| x.line_bytes())
}
fn read_line_str() -> String {
    unsafe { String::from_utf8_unchecked(read_line()) }
}
fn read<T: FromStr>() -> T {
    read_token_str().parse::<T>().ok().expect("failed parse")
}
fn read_vec<T: FromStr>(n: usize) -> Vec<T> {
    (0..n).map(|_| read()).collect()
}
fn read_vec2<T: FromStr>(n: usize, m: usize) -> Vec<Vec<T>> {
    (0..n).map(|_| read_vec(m)).collect()
}

struct Scanner<R: Read> {
    src: R,
    _buf: Vec<u8>,
    _pt: usize, // pointer
    _rd: usize, // bytes read
}

#[allow(dead_code)]
impl<R: Read> Scanner<R> {
    fn new(src: R) -> Scanner<R> {
        Scanner {
            src,
            _buf: vec![0; IO_BUF_SIZE],
            _pt: 1,
            _rd: 1,
        }
    }

    fn _check_buf(&mut self) {
        if self._pt == self._rd {
            self._rd = self.src.read(&mut self._buf).unwrap_or(0);
            self._pt = (self._rd == 0) as usize;
        }
    }

    // returns true if end of file
    fn eof(&mut self) -> bool {
        self._check_buf();
        self._rd == 0
    }

    // filters \r, returns \0 if eof
    fn byte(&mut self) -> u8 {
        loop {
            self._check_buf();
            if self._rd == 0 {
                return 0;
            }
            let res = self._buf[self._pt];
            self._pt += 1;
            if res != b'\r' {
                return res;
            }
        }
    }

    fn bytes_no_skip(&mut self, n: usize) -> Vec<u8> {
        (0..n).map(|_| self.byte()).collect()
    }
    fn bytes(&mut self, n: usize) -> Vec<u8> {
        let res = self.bytes_no_skip(n);
        self.byte();
        res
    }
    fn bytes2(&mut self, n: usize, m: usize) -> Vec<Vec<u8>> {
        (0..n).map(|_| self.bytes(m)).collect()
    }

    fn token_bytes(&mut self) -> Vec<u8> {
        let mut res = Vec::new();
        let mut c = self.byte();
        while c <= b' ' {
            if c == b'\0' {
                return res;
            }
            c = self.byte();
        }
        loop {
            res.push(c);
            c = self.byte();
            if c <= b' ' {
                return res;
            }
        }
    }

    fn line_bytes(&mut self) -> Vec<u8> {
        let mut res = Vec::new();
        let mut c = self.byte();
        while c != b'\n' && c != b'\0' {
            res.push(c);
            c = self.byte();
        }
        res
    }
}

fn main() {
    let t: usize = sc.next();
    for i in 0..t {
        solve(&mut sc);
    }
}
